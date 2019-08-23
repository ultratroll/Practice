#include "FractalCreator.h"
#include <vector>
#include <assert.h>

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

void FractalCreator::Run(string Name)
{
	CalculateIterations();
	CalculateRangePixelTotals();
	DrawFractal();
	WriteBitmap(Name);
}

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
	int _totalPixels= 0;
	for (int i=0; i< Mandelbrot::MAXITERATIONS ; i++)
	{
		_totalPixels+= _histogram[i];
	}

	std::cout<< "total pixels " << _totalPixels << std::endl;


	for (int y=0; y< _height; y++)
	{
		for (int x=0; x< _width; x++)
		{
			int Iterations= _fractalData[y*_width+x];
			int range= GetRange(Iterations);
			int allPixelsInRange = _rangesTotalPixels[range]; //  how many pixels are in this range
			int startingIterationsInRange = _ranges[range]; // with how many iteration  does this range start

			uint8_t red = 0;
			uint8_t green =  0;
			uint8_t blue = 0;

			FRGB& startColor= _colors[range];
			FRGB& endColor= _colors[range+1];
			FRGB  diffColor = endColor - startColor; 

			if (Iterations != Mandelbrot::MAXITERATIONS)
			{
				double Hue= 0.0;
				int totalPixels = 0; // To sume the pixels bettwen the start of the range and the actual number of iterations in this pixel

				// Lets count all pixels from the start of the iterations for the range until the actual number of iterations
				for (int i=startingIterationsInRange; i <= Iterations; i++)
				{
					totalPixels+= _histogram[i];
					//Hue+= ((double) _histogram[i])/_totalPixels;

				}

				Hue= (double)totalPixels/allPixelsInRange;

				red = startColor.R + diffColor.R* Hue;
				green = startColor.G + diffColor.G* Hue;
				blue = startColor.B + diffColor.B* Hue;

				_bitmap.SetPixel(x,y, red, green, blue);
			}
		}
	}	
}

void FractalCreator::AddZoom(const FZoom& Zoom)
{
	_zoomList.AddZoom(Zoom);
}

void FractalCreator::AddRange(double EndRange, FRGB& Endcolor)
{
	//Lets handle our ranges vector by iterations, thus, the rational multiplied by the max number of iterations
	// ranges will be indexed by number of iterations
	_ranges.push_back(EndRange * Mandelbrot::MAXITERATIONS);
	_colors.push_back(Endcolor);

	// Doing this with all but the first range added
	if (_bGotFirstRange)
	{
		_rangesTotalPixels.push_back(0);
	}

	// flag to enssure we cannow add pixels now, because we dont count the first range (for 4 ranges we actually have 3 ranges)
	_bGotFirstRange= true;
}

void FractalCreator::CalculateRangePixelTotals()
{
	int rangeIndex = 0;

	for (int i= 0; i< Mandelbrot::MAXITERATIONS; i++)
	{
		const int pixels= _histogram[i];

		// Check if we need to advance the range index
		// rangeIndex+1 because the first value doesnt count
		if (_ranges[rangeIndex+1] <= i)
		{
			rangeIndex++;
		}

		_rangesTotalPixels[rangeIndex]+= pixels;
	}

	// For debug
	for (int value : _rangesTotalPixels)
		std::cout << "Total pixels "<< value << std::endl;

		for (int value : _ranges)
		std::cout << "Range "<< value << std::endl;
}


void FractalCreator::WriteBitmap(string Name)
{
	_bitmap.Write(Name);

	std::cout << "Finished !" << std::endl;
}

int FractalCreator::GetRange(int Iterations) const
{
	int range= 0;

	for (int i= 1; i < _ranges.size(); i++)
	{
		if (Iterations < _ranges[i])
			break;
		range++;
	}

	assert(range>=0 && range < _ranges.size());

	return range;
}

}