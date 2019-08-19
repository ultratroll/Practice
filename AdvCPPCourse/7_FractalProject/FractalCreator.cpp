#include "FractalCreator.h"

namespace fractals
{

FractalCreator::FractalCreator(int Width, int Height) : 
	_width(Width), 
	_height(Height),
	_histogram(new int[Mandelbrot::MAXITERATIONS]),
	_fractalData(new int[_width * _height]),
	_bitmap(_width, _height),
	_zoomList(_width, _height)
{
	fill(_histogram.get(), _histogram.get()+Mandelbrot::MAXITERATIONS,0);
	fill(_fractalData.get(), _fractalData.get()+_width*_height,0);
}

FractalCreator::~FractalCreator()
{}

void FractalCreator::CalculateIterations()
{
	for (int y=0; y< _height; y++)
	{
		for (int x=0; x< _width; x++)
		{
			// Zoom algorithm to convert pixel to the dessired coordinates
			pair<double, double> Coordinates = _zoomList.DoZoom(x,y);

			int Iterations= Mandelbrot::GetIterations(Coordinates.first, Coordinates.second);

			_fractalData[y* _width+ x] = Iterations;
			
			if (Iterations != Mandelbrot::MAXITERATIONS)
				_histogram[Iterations]++;
		}
	}
}

void FractalCreator::DrawFractal()
{
	// Lets count the total of pixels by adding all the pixel count per iteration in the histogram
	int totalPixels= 0;
	for (int i=0; i< Mandelbrot::MAXITERATIONS ; i++)
	{
		totalPixels+= _histogram[i];
	}

	for (int y=0; y< _height; y++)
	{
		for (int x=0; x< _width; x++)
		{
			
			uint8_t Red = 0;
			uint8_t Green =  0;
			uint8_t Blue = 0;

			int Iterations= _fractalData[y*_width+x];

			if (Iterations != Mandelbrot::MAXITERATIONS)
			{
				double Hue= 0.0;

				// We add in hue the a proportion count of all pixels with lesser iterations
				// in a way we add to the color in proportion to the number of pixel with lesser or equal number of iterations
				// The more pixels in that and lesser iterations, the brither the color
				for (int i=0; i <= Iterations; i++)
					Hue+= ((double) _histogram[i])/totalPixels;

				//Green = pow(255, Hue); // Roxana likes this one more :)
				Red = 255* Hue; // This one looks a lot more glowy

				_bitmap.SetPixel(x,y, Red, Green, Blue);
			}
		}
	}	
}

void FractalCreator::AddZoom(const FZoom& Zoom)
{
	_zoomList.AddZoom(Zoom);
}

void FractalCreator::WriteBitmap(string name)
{
	_bitmap.Write(name);

	std::cout << "Finished !" << std::endl;
}

}