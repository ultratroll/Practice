#include <iostream>
#include <string>

using namespace std;

class Test
{
private:
	int one{1};
	int two{2};
public:
	void Run()
	{
		int three= 3;
		int four= 4;

		// We can add this, and the lambda expressions will capture by reference the class instance, including private variables as one and two
		// this only works by reference
		auto pLambda= [this, three, four]()
		{
			one= 234;
			std::cout<< one << std::endl;
			std::cout<< two << std::endl;
			std::cout<< three << std::endl;
			std::cout<< four << std::endl;
		};
		pLambda();
	}

};

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

	// Example of lambda expression capturing this in Run call
	Test Testo;
	Testo.Run();
}