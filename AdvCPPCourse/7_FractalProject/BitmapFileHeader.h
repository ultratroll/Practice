
#ifndef BITMAPHEADER_H
#define BITMAPHEADER_H

#include <cstdint>

using namespace std;

#pragma pack(2)

struct FBitmapFileHeader
{
	char Header[2]{'B','M'};
	int32_t filesize;
	int32_t reserved{0};
	int32_t dataOffset;
};

#pragma pack(pop)

#endif