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

	for (int y=0; y< Height; y++)
	{
		for (int x=0; x< Width; x++)
		{
			// mapping ot value bettwen -1 and 1
			double xFractal = (x-Width/2) * 2.0/Width;
			double yFractal = (y-Height/2) * 2.0/Height;

			int Iterations= Mandelbrot::GetIterations(xFractal, yFractal);

			uint8_t Red= (uint8_t)(256* (double)Iterations/Mandelbrot::MAXITERATIONS);

			bit.SetPixel(x,y, Red,0,0);

			if (Red < min) min= Red;
			if (Red > max) max= Red;

		}
	}

	std::cout << "min " << min << std::endl;
	std::cout << "max " << max << std::endl;

	bit.Write("FractalTest.bmp");

	std::cout << "Finished !" << std::endl;

	return 0;
}