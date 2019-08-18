#ifndef ZOOMLIST_H
#define ZOOMLIST_H

#include "Zoom.h"
#include <vector>
#include <utility>

using namespace std;

namespace  fractals
{

class ZoomList
{
private:
	double CenterX{0};
	double CenterY{0};
	double Scale{1.0};
	int Width{0};
	int Height{0};
	vector<FZoom> Zooms;
public:

ZoomList(int Width, int Height);

void AddZoom(const FZoom& Zoon);

pair<double, double> DoZoom(int X, int Y);

};

}

#endif