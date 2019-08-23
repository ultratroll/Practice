#ifndef FRACTALCREATOR_H
#define FRACTALCREATOR_H

#include "Bitmap.h"
#include "RGB.h"
#include "Mandelbrot.h"
#include <math.h>
#include "ZoomList.h"
#include <string>

using namespace bitmaps;
using namespace std;

namespace fractals
{

class FractalCreator
{
private:
	int _width{0};
	int _height{0};

	// Sum of all pixels considered in the fractal. some of them will be ignored by the mandelbrot condition, thus is not simply width * height
	int _totalPixels{0};

	// This _histogram is for saving the number of pixels per iteration. Not counting the pixels where we reach the max number of iterations, because those
	// are not useful data for the fractal, on the pixels the algorithm "gave up"
	unique_ptr<int []> _histogram;

	// the actual fractal, lets save the number of iterations for each pixel
	unique_ptr<int []> _fractalData;

	Bitmap _bitmap;
	
	ZoomList _zoomList;

	// Ranges and their colors, to differentiate visually by iterations
	vector<int> _ranges;
	vector<FRGB>  _colors;
	vector<int> _rangesTotalPixels;

	bool _bGotFirstRange{false};

public:

	FractalCreator(const int Width, const int Height);
	~FractalCreator();
	void FractalCreator::Run(string Name);
	void AddZoom(const FZoom& Zoom);

	/** 
		Adds a end color for a certain EndRange (a fraction bettwen 0 and 1 proportional to the iterations). Starts from the previously defined range position so to speak 
		and color.

		The idea here is to have different colors for different iterations ranges. 
	*/
	void AddRange(double EndRange, FRGB& Endcolor);

	// Calculate how many pixels per pixel range are being saved.
	void CalculateRangePixelTotals();

	// Gets the range based on the number of iterations
	int GetRange(int Iterations) const;

private:
	void CalculateIterations();
	void DrawFractal();
	void WriteBitmap(string name);
	
	
};

}

#endif