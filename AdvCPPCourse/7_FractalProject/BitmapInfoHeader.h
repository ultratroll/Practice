
#ifndef BITMAPINFOHEADER_H
#define BITMAPINFOHEADER_H

#include <cstdint>

using namespace std;

#pragma pack(2)

namespace Fractal
{

struct FBitmapInfoHeader
{
	int32_t headerSize{40};
	int32_t width;
	int32_t height;
	int16_t planes{1}; // Not sure for what but needs to be there
	int16_t bitsPerPixel{24}; // 8 bit for each color, RGB
	int32_t compression{0};
	int32_t dataSize{0};
	int32_t horizontalResolution{2400};
	int32_t verticalResolution{2400};
	int32_t colors{0};
	int32_t importantColors{0};
};

}

#pragma pack(pop)

#endif