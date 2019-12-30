#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

class ConsoleTest : public olc::PixelGameEngine
{
private:
	olc::vi2d vWorldSize = {14,10}; // Tiles in the world
	olc::vi2d vTileSize = {40,40}; // Size of a tile in pixels. notice how the width is twice the height, important convention
	olc::vi2d vOrigin = {5,5}; // Where to start drawing
	int *pWorld = nullptr; // Int array to store the 2d world array

public:
	ConsoleTest()
	{
		sAppName = "AStar";
		pWorld = new int[vWorldSize.x * vWorldSize.y] {rand() % 255};
	}

public:
	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		// called once per frame
		for (int x = 0; x < ScreenWidth(); x++)
			for (int y = 0; y < ScreenHeight(); y++)
				DrawRect(x+2*x, y+2*y, x+vTileSize.x-2*x, y+vTileSize.y-2*y, olc::RED);
				//Draw(x, y, olc::Pixel(rand() % 255, rand() % 255, rand()% 255));	
		return true;
	}
};


int main()
{
	ConsoleTest demo;
	if (demo.Construct(256, 240, 4, 4))
		demo.Start();

	return 0;
}