#ifndef MANDELBROT_h
#define MANDELBROT_h

namespace fractals
{

class Mandelbrot
{
public:
	static const int MAXITERATIONS = 2500; // 1000
public:
	static int GetIterations(double X, double Y);
};

}

#endif