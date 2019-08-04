#include <iostream>
#include <string>

using namespace std;

int main()
{
	int one = 1;
	int two = 2;
	int three = 3;

	// Capture one and two by value
	[one, two](){std::cout << one << " " << two << std::endl;}();

	// Capture all local variables by value
	[=](){std::cout << one << " " << two << std::endl;}();

	// Capture all local variables by value and three by reference
	[=, &three](){ three=7; std::cout << one << " " << three << std::endl;}();

	std::cout << three << std::endl;

	// Capture all local variables by reference
	[&](){std::cout << one << " " << three << std::endl;}();

	// Capture all local variables by reference but one by value
	[&, one](){std::cout << one << " " << three << std::endl;}();
}