#include "FractalCreator.h"
using namespace std;
using namespace bitmaps;
using namespace fractals;

int main()
{
	const int _width{800};
	const int _height{600};

	FractalCreator fractalMaker(_width, _height);

	fractalMaker.AddRange(0.0, FRGB(255,255,0));
	fractalMaker.AddRange(0.1, FRGB(0,0,255));
	fractalMaker.AddRange(0.2, FRGB(0,255,0));
	fractalMaker.AddRange(0.3, FRGB(255,0,0));
	fractalMaker.AddRange(0.4, FRGB(0,255,0));
	fractalMaker.AddRange(0.5, FRGB(0,0,255));
	fractalMaker.AddRange(0.6, FRGB(0,255,0));
	fractalMaker.AddRange(0.7, FRGB(255,0,0));
	fractalMaker.AddRange(0.8, FRGB(0,255,0));
	fractalMaker.AddRange(0.9, FRGB(0,0,255));
	fractalMaker.AddRange(1.0, FRGB(0,255,0));
/*
	fractalMaker.AddRange(0.0, FRGB(0,0,0));
	fractalMaker.AddRange(0.3, FRGB(255,0,0));
	fractalMaker.AddRange(0.5, FRGB(255,0,0));
	fractalMaker.AddRange(1.0, FRGB(255,0,0));
*/

	fractalMaker.AddZoom(FZoom(_width/2, _height/2, 4.0/_width)); // 4.0/_width is a nice zoom to see the fractal
	fractalMaker.AddZoom(FZoom(295, _height-202, 0.1));
	fractalMaker.AddZoom(FZoom(312, _height-304, 0.1));
	fractalMaker.AddZoom(FZoom(181, _height-289, 0.1));
	fractalMaker.AddZoom(FZoom(_width/2, _height/2, 0.1));
	fractalMaker.AddZoom(FZoom(_width/2, _height/2, 0.1));

	fractalMaker.Run("fractal9.bmp");

	return 0;
}