#include "Bitmap.h"

#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include <iostream>
#include <fstream>

using namespace std;

namespace bitmaps
{

Bitmap::Bitmap()
{
}

Bitmap::Bitmap(int Width, int Height) : _width(Width), _height(Height), _pPixelData( new uint8_t[Width*Height*3]{} )
{
	std::cout << "IT WAS I, BITMAP" << std::endl;
}

bool Bitmap::Write(string Filename)
{
	std::cout << "Writting file" << std::endl;
	FBitmapFileHeader Header;
	FBitmapInfoHeader Info;

	Header.filesize= sizeof(FBitmapFileHeader) + sizeof(Info) + _width*_height*3;
	Header.dataOffset= sizeof(FBitmapFileHeader) + sizeof(Info);

	Info.width = _width;
	Info.height = _height;

	ofstream File;

	File.open(Filename, ios::out| ios::binary);

	if (!File)
		return false;

	File.write((char *)&Header, sizeof(Header));
	File.write((char *)&Info, sizeof(Info));
	File.write((char *)(_pPixelData.get()), _width*_height*3);

	File.close();
	
	if (!File)
		return false;

	return true;
}

void Bitmap::SetPixel(int X, int Y, uint8_t Red, uint8_t Green, uint8_t Blue)
{
	//std::cout << "Setting pixel" << std::endl;

	uint8_t* pPixel= _pPixelData.get(); // getting raw pointer

	pPixel+= Y*3*_width + X*3;

	// backward order for colors because its little endian
	pPixel[0]= Blue;
	pPixel[1]= Green;
	pPixel[2]= Red;

}

Bitmap::~Bitmap()
{}

} // namespace bitmaps

/*
// Example
const int Width{800};
const int Height{600};

Bitmap bit(Width, Height);

for (int i= 0; i< Width; i++)
	bit.SetPixel(Height/2, i, 255, 0, 0);

for (int i= 0; i< Height; i++)
	bit.SetPixel(Width/2, i, 255, 0, 0);

bit.SetPixel(Width/2, 100, 255, 255, 255);
*/