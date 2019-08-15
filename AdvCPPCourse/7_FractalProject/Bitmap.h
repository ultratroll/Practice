#ifndef BITMAP_H
#define BITMAP_h

#include <string>
#include <cstdint>

using namespace std;

namespace bitmaps
{

class Bitmap
{
private:
	int _width{0};
	int _height{0};
	unique_ptr<uint8_t[]>_pPixelData{nullptr};

public:

	// Default constructor
	Bitmap();

	// Constructor
	Bitmap(int Width, int Height);

	// Write bitmap to file
	bool Write(string Filename);

	// Set pixel
	void SetPixel(int X, int Y, uint8_t Red, uint8_t Green, uint8_t Blue);

	~Bitmap();
};

}

#endif