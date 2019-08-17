#include <iostream>
#include <string>

#include "Bitmap.h"
#include "Mandelbrot.h"

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
	//	bit.SetPixel(i, Width/2, 0, 255, 0);

	bit.SetPixel(Width/2, 100, 255, 255, 255);

	double min = 999999;
	double max = -999999;

	unique_ptr<int []> Histogram(new int[Mandelbrot::MAXITERATIONS+1]{0});

	for (int y=0; y< Height; y++)
	{
		for (int x=0; x< Width; x++)
		{
			const double Offset = -200.0;
			const double Scale = 1;

			// mapping ot value bettwen -1 and 1
			double xFractal = (x-Width/2 +Offset) * 2.0/Height;
			double yFractal = (y-Height/2) * 2.0/Height;

			xFractal*= Scale;
			yFractal*= Scale;

			int Iterations= Mandelbrot::GetIterations(xFractal, yFractal);
			Histogram[Iterations]++;

			uint8_t Color= (uint8_t)(256* (double)Iterations/Mandelbrot::MAXITERATIONS);

			Color= Color*Color*Color;

			bit.SetPixel(x,y, 80, Color,0);

			if (Color < min) min= Color;
			if (Color > max) max= Color;

		}
	}

	std::cout << std::endl;

	int Count= 0;

	for (int i=0; i<= Mandelbrot::MAXITERATIONS ; i++)
	{
		std::cout << Histogram[i] << " " << std::flush; 
		Count+= Histogram[i];
	}

	// Verifying the number of pixels is right
	std::cout << Count << " ; " << Width*Height << endl;

	std::cout << std::endl;

	std::cout << "min " << min << std::endl;
	std::cout << "max " << max << std::endl;

	bit.Write("FractalTest.bmp");

	std::cout << "Finished !" << std::endl;

	return 0;
}