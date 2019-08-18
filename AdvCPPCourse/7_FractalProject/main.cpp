#include <iostream>
#include <string>

#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
#include <math.h>

using namespace std;
using namespace bitmaps;
using namespace fractals;

int main()
{
	const int Width{800};
	const int Height{600};

	Bitmap bit(Width, Height);

	//for (int i= 0; i< Width; i++)
	//	bit.SetPixel(Height/2, i, 255, 0, 0);

	//for (int i= 0; i< Height; i++)
	//	bit.SetPixel(Width/2, i, 255, 0, 0);

	//bit.SetPixel(Width/2, 100, 255, 255, 255);

	double min = 999999;
	double max = -999999;

	ZoomList Zooms(Width, Height);
	Zooms.AddZoom(FZoom(Width/2, Height/2, 2.0/Width)); // 4.0/Width is a nice zoom to see the fractal

	// This histogram is for saving the number of pixels per iteration. Not counting the pixels where we reach the max number of iterations, because those
	// are not useful data for the fractal, on the pixels the algorithm "gave up"
	unique_ptr<int []> Histogram(new int[Mandelbrot::MAXITERATIONS]);

	// the actual fractal, lets save the number of iterations for each pixel
	unique_ptr<int []> Fractal(new int[Width * Height]); // For some reason cl complains when initializing to zeroes this enourmous array, so wont

	fill(Histogram.get(), Histogram.get()+Mandelbrot::MAXITERATIONS,0);
	fill(Fractal.get(), Fractal.get()+Width*Height,0);

	for (int y=0; y< Height; y++)
	{
		for (int x=0; x< Width; x++)
		{
			// mapping ot value bettwen -1 and 1
			//double xFractal = (x-Width/2 -200) * 2.0/Height;
			//double yFractal = (y-Height/2) * 2.0/Height;

			// Now we do it with the zoom algorithm
			pair<double, double> Coordinates = Zooms.DoZoom(x,y);

			int Iterations= Mandelbrot::GetIterations(Coordinates.first, Coordinates.second);

			Fractal[y* Width+ x] = Iterations;
			
			// For our color calculations we want to exclude cases where iterations reached max, those cases are usually marked in black
			/*
			The problem is that there are a lot of coordinates for which we reach the maximum number of iterations without the absolute value of the associated complex number 
			in the algorithm going above 2. The majority of those pixels are never going to go above 2 no matter how many iterations we to through, and we normally colour them
			black. When we calculate the histogram to colour the pixels that do escape above 2, we want to distribute colours nicely over those pixels. So if we have a whole 
			massive bunch of pixels in there that are going to be black anyway, that skews the results.

			So we get rid of them.

			There's a good explanation here: https://math.stackexchange.com/questions/16970/a-way-to-determine-the-ideal-number-of-maximum-iterations-for-an-arbitrary-zoom

			To make an analogy, imagine you wanted give money to charities that prevent flooding. You decide to allocate money based on how much time any particular 
			thousand-mile-square piece of the planet is under water in a given year on average. You need to exclude those areas of the planet that are actually ocean; there 
			are a lot of them, and if you include them then your money will end up going mostly on ocean (where you won't find suitable charities anyway) instead of being 
			distributed nicely over the bits that could use your money.

			So that's what we're doing here. We want to count pixels that we intend to colour, distribute colours nicely over those, and exclude those pixels that we intend 
			to be black, which are the majority when you look at the Mandelbrot as a whole.
			*/
			if (Iterations != Mandelbrot::MAXITERATIONS)
				Histogram[Iterations]++;

			// To reinforce it, another explanation
			/*
				int iterations = 0;
				while (iterations < it)
				{
					z = z * z + c;
					if (abs(z) > 2) { break; }
					iterations += 1;
				}
				return iterations;

				At each iteration z = z*z + c , where c is our (x,y) point in the complex numbers plane and z is the running total of this (initially set to 0, of course). We 
				iterate until abs(z) > 2  Problem is that for some (x,y) this is believed to never happens, for any number of iterations.

				We need to put some limit, so we set MAX_ITERATIONS  and after that we believe that these poins will never "go out". But...

				Let us say that we have only 10 iterations MAX. It is possible that a pair (x,y) "gone out" at the 10th iteration, and a pair (a,b) did not, and possibly  will
				never do for any number of iterations.  Both (x,y) and (a,b) are in the SAME histogram column, 11th column. And they are very different in nature, so we can not
				use this column in the bitmap, as John explained. It contains points that probably will never "go out" and we want to draw a bitmap based on the distribution of
				the number of iterations required to do that, abs()  value exceed 2.
			*/
		}
	}

	std::cout << std::endl;

	int Total= 0;
	for (int i=0; i< Mandelbrot::MAXITERATIONS ; i++)
	{
		Total+= Histogram[i];
	}

	for (int y=0; y< Height; y++)
	{
		for (int x=0; x< Width; x++)
		{
			
			uint8_t Red = 0;
			uint8_t Green =  0;
			uint8_t Blue = 0;


			int Iterations= Fractal[y*Width+x];

			if (Iterations != Mandelbrot::MAXITERATIONS)
			{
				double Hue= 0.0;

				// We add in hue the a proportion count of all pixels with lesser iterations
				// in a way we add to the color in proportion to the number of pixel with lesser or equal number of iterations
				for (int i=0; i <= Iterations; i++)
					Hue+= ((double) Histogram[i])/Total;

				Green = pow(255, Hue);

				bit.SetPixel(x,y, Red, Green, Blue);
			}

			// old way, as my original fractal
			/*
			uint8_t Color= (uint8_t) (256 * (double) Iterations / Mandelbrot::MAXITERATIONS);

			Color= Color * Color *Color;

			bit.SetPixel(x,y, 80, Color, 0);
			*/
		}
	}	

	std::cout << std::endl;

	bit.Write("FractalTest.bmp");

	std::cout << "Finished !" << std::endl;

	return 0;
}