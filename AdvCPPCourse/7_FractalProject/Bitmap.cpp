#include "Bitmap.h"

#include <iostream>

using namespace std;

namespace fractal
{

Bitmap::Bitmap()
{
	;
}

Bitmap::Bitmap(int Height, int Width) : _height(Height), _width(Width)
{
	;
}

bool Bitmap::Write(string Filename)
{
	return true;
}

void Bitmap::SetPixel(int X, int Y, uint8_t Red, uint8_t Green, uint8_t Blue)
{
	;
}

Bitmap::~Bitmap()
{}

}