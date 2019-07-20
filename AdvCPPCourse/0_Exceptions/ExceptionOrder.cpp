#include <iostream>
#include <exception>

using namespace std;

// Ultratroll: Example to play with exception order

void WrongTest()
{
	bool Error1 = true;
	bool Error2 = true;

	if (Error1)
	{
		throw bad_alloc();
	}

	if (Error1)
	{
		throw exception();
	}
}

int main()
{
	try
	{
		WrongTest();
	}
	catch(const bad_alloc& e)
	{
		std::cout << e.what() << " .. bad alloc \n";
	}
	catch(const exception& e)
	{
		std::cout << e.what() << " .. exception \n";
	}

	std::cout<< "program didnt crash !" << std::endl;
}

