#include <iostream>
#include <string>

using namespace std;

void Test(void (*pFunction)())
{
	std::cout << "Test::";
	pFunction();
}

int main()
{
	// A lambda expression, pretty much a function without name
	[](){std::cout << "Hello there"<< std::endl;};

	// Can be called directly
	[](){std::cout << "Call directly"<< std::endl;}();

	// stored and called later
	auto function = [](){std::cout << "Stored lambda expression"<< std::endl;};
	function();

	// Passed to other functions
	Test(function);

	// And we can easily pass the lambda expression directly
	Test([](){std::cout << "Directly passing lambda expression"<< std::endl;});
}