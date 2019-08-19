#ifndef FRACTALCREATOR_H
#define FRACTALCREATOR_H

#include "Bitmap.h"
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

	// This _histogram is for saving the number of pixels per iteration. Not counting the pixels where we reach the max number of iterations, because those
	// are not useful data for the fractal, on the pixels the algorithm "gave up"
	unique_ptr<int []> _histogram;

	// the actual fractal, lets save the number of iterations for each pixel
	unique_ptr<int []> _fractalData;

	Bitmap _bitmap;
	
	ZoomList _zoomList;

public:

	FractalCreator(const int Width, const int Height);
	~FractalCreator();
	void CalculateIterations();
	void DrawFractal();
	void AddZoom(const FZoom& Zoom);
	void WriteBitmap(string name);

};

}

#endif