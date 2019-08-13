#ifndef BITMAP_H
#define BITMAP_h

#include <string>
#include <cstdint>

using namespace std;

namespace fractal
{

class Bitmap
{
private:
	int _height{0};
	int _width{0};

public:
	Bitmap();

	Bitmap(int Height, int Width);

	bool Write(string Filename);

	void SetPixel(int X, int Y, uint8_t Red, uint8_t Green, uint8_t Blue);

	~Bitmap();
};

}

#endif