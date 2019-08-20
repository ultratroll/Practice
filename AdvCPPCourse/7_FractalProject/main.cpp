#include "FractalCreator.h"
using namespace std;
using namespace bitmaps;
using namespace fractals;

int main()
{
	const int _width{800};
	const int _height{600};

	FractalCreator fractalMaker(_width, _height);

	fractalMaker.AddZoom(FZoom(_width/2, _height/2, 4.0/_width)); // 4.0/_width is a nice zoom to see the fractal
	fractalMaker.AddZoom(FZoom(295, _height-202, 0.1));
	fractalMaker.AddZoom(FZoom(312, _height-304, 0.1));
	fractalMaker.AddZoom(FZoom(181, _height-289, 0.1));

	fractalMaker.Run("fractal3.bmp");

	return 0;
}