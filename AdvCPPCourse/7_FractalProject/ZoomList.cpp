#include "ZoomList.h"
#include <iostream>

using namespace std;

namespace fractals
{

ZoomList::ZoomList(int Width, int Height): Width(Width), Height(Height)
{}

void ZoomList::AddZoom(const FZoom& Zoom)
{
	Zooms.push_back(Zoom);

	// From where the user clicks we want to have the new center by substracting, and then apply the fractal scale
	CenterX+= (Zoom.X-Width/2)*Scale;
	CenterX+= (Zoom.Y-Height/2)*Scale;

	// Update the scale
	Scale*= Zoom.Scale;

	std::cout << "(" << CenterX << ", " << CenterY << ", " <<  Scale << ")" << std::endl;
}

pair<double, double> ZoomList::DoZoom(int X, int Y)
{
	double XFractal= (X-Width/2)*Scale+ CenterX;
	double YFractal= (Y-Height/2)*Scale+ CenterY;

	return pair<double, double>(XFractal, YFractal);
}

}