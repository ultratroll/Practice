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

		//Optimization suggested: For anyone who finds that their code is slow, the abs function probably includes a square root, or some approximation, so coding up
		// the quit condition as norm(z) > 4.0 instead of abs(z) > 2.0 will speed up the code dramatically.
		if (norm(Z) > 4.0)
		{
			break;
		}
		Iterations++;
	}

	return Iterations;
}

}