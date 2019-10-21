#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

class Isometric : public olc::PixelGameEngine
{

private:

	olc::vi2d vWorldSize = {14,10}; // Tiles in the world
	olc::vi2d vTileSize = {40,20}; // Size of a tile in pixels. notice how the width is twice the height, important convention
	olc::vi2d vOrigin = {5,5}; // Where to start drawing
	olc::Sprite *spriteIsom = nullptr; // For the sprite
	int *pWorld = nullptr; // Int array to store the 2d world array

public:
	Isometric()
	{
		sAppName = "Example";
	}

	bool OnUserCreate() override
	{
		spriteIsom = new olc::Sprite("isometric_demo.png");
		pWorld = new int[vWorldSize.x *vWorldSize.y] {0}; // Init the 2d only world array with zeroes
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{

		// Mouse and cell where mouse lies
		olc::vi2d vMouse = { GetMouseX(), GetMouseY() }; // Mouse in world
		olc::vi2d vCell = { vMouse.x /vTileSize.x, vMouse.y / vTileSize.y  }; // Active cell
		olc::vi2d vOffset = { vMouse.x % vTileSize.x, vMouse.y % vTileSize.y  }; // Mouse offset into cell

		olc::vi2d vSelectedCell =
		{
			(vCell.y- vOrigin.y) + (vCell.x- vOrigin.x),
			(vCell.y- vOrigin.y) - (vCell.x- vOrigin.x)
		};

		// Sample into cell offset colour...the trick is checking the color and the region witht he offset to know which cell is actually being selected, clever cheat
		olc::Pixel col = spriteIsom->GetPixel(3 * vTileSize.x + vOffset.x, vOffset.y);

		// "Bodge" selected cell by sampling corners
		if (col == olc::RED) vSelectedCell += {-1, +0};
		if (col == olc::BLUE) vSelectedCell += {+0, -1};
		if (col == olc::GREEN) vSelectedCell += {+0, +1};
		if (col == olc::YELLOW) vSelectedCell += {+1, +0};

		// called once per frame
		Clear(olc::WHITE);

		auto ToScreen = [&](int x, int y)
		{
			// Trough drawing and factorizing these simple formuals arise. Assuming that weidth of tile is twice its height
			return olc::vi2d
			{ 
				(x-y)*(vTileSize.x/2) + vOrigin.x*(vTileSize.x), 
				(x+y)*(vTileSize.y/2) + vOrigin.y*(vTileSize.y)
			};

		};

		SetPixelMode(olc::Pixel::MASK);

		// First Y from the top of the screen to the bottom, because we want to draw first the items above and finally the remaining ones
		for (int j= 0; j < vWorldSize.y; j++)
		{
			for (int i= 0; i < vWorldSize.x; i++)
			{
				// Starting point to draw this sprite
				olc::vi2d vWorld = ToScreen(i, j);

				// Tile to draw
				switch (pWorld[j*vWorldSize.x + i])
				{
					case 0:
						// Invisible tile
						DrawPartialSprite(vWorld.x, vWorld.y, spriteIsom, 1 * vTileSize.x, 0, vTileSize.x, vTileSize.y);
						break;
					
					default:
						break;
				}
			}
		}

		// Selection sprite
		SetPixelMode(olc::Pixel::ALPHA);
		olc::vi2d vSelectdWorld = ToScreen(vSelectedCell.x, vSelectedCell.y);

		DrawPartialSprite(vSelectdWorld.x, vSelectdWorld.y, spriteIsom, 0 * vTileSize.x, 0, vTileSize.x, vTileSize.y);
		
		SetPixelMode(olc::Pixel::NORMAL);

		//DrawRect(vCell.x * vTileSize.x, vCell.y * vTileSize.y, vTileSize.x, vTileSize.y, olc::RED);

		// Draw Debug Info
		DrawString(4, 4, "Mouse   : " + std::to_string(vMouse.x) + ", " + std::to_string(vMouse.y), olc::BLACK);
		DrawString(4, 14, "Cell    : " + std::to_string(vCell.x) + ", " + std::to_string(vCell.y), olc::BLACK);
		DrawString(4, 24, "Selected: " + std::to_string(vSelectedCell.x) + ", " + std::to_string(vSelectedCell.y), olc::BLACK);

		return true;
	}

};


int main()
{
	Isometric demo;
	if (demo.Construct(512, 480, 2, 2))
		demo.Start();

	return 0;
}
