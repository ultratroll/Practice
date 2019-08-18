//#ifndef ZOOM_H
#define ZOOM_H

#include <iostream>

namespace fractals
{
struct FZoom
{
	int X{0};
	int Y{0};
	double Scale{0.0};

	FZoom(int X, int Y, double Scale) :X(X), Y(Y), Scale(Scale){};
};
}

//#endif