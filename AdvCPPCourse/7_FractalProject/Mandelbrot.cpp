#include "Mandelbrot.h"
#include <complex>

using namespace std;

namespace fractals
{

int Mandelbrot::GetIterations(double X, double Y)
{
	complex<double> Z = 0;
	complex<double> C(X,Y);

	int Iterations = 0;

	while ( Iterations < Mandelbrot::MAXITERATIONS)
	{
		Z= Z*Z + C;

		if (abs(Z) > 2)
		{
			break;
		}
		Iterations++;
	}

	return Iterations;
}

}