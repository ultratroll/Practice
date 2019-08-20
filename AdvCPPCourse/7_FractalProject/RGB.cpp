#include "RGB.h"

namespace bitmaps
{

	FRGB::FRGB(double R, double G, double B) : R(R) , G(G), B(B)
	{}

	FRGB operator-(const FRGB& first, const FRGB& second)
	{
		return FRGB(first.R - second.R, first.G - second.G, first.B - second.B);
	}
}