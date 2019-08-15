#include <iostream>
#include <string>

#include "Bitmap.h"

using namespace std;
using namespace bitmaps;

int main()
{
	const int Width{800};
	const int Height{600};

	Bitmap bit(Width, Height);

	//for (int i= 0; i< Width; i++)
	//	bit.SetPixel(Height/2, i, 255, 0, 0);

	//for (int i= 0; i< Height; i++)
	//	bit.SetPixel(i, Width/2, 0, 255, 0);

	bit.SetPixel(Width/2, 100, 255, 255, 255);

	bit.Write("FractalTest.bmp");

	std::cout << "Finished !" << std::endl;

	return 0;
}