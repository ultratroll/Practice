#ifndef RGB_H
#define RGB_H

namespace bitmaps
{
	struct FRGB
	{
		double R;
		double G;
		double B;

		FRGB(double R, double G, double B);

	};

	// global
	FRGB operator-(const FRGB& first, const FRGB& second);
}

#endif