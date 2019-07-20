#include <iostream>
#include <string>
using namespace std;

// Ultratroll: Basic exception examples

void MightGoWrong()
{
	bool Error1 = false;
	bool Error2 = false;
	bool Error3 = true;

	if (Error1)
	{
		throw 8;
	}
	if (Error2)
	{
		throw "Something went wrong. ";
	}
	if (Error3)
	{
		// As exceptions work, this string will clean itself
		throw string("Something else went wrong. ");
	}
}

int main()
{
	try
	{
		MightGoWrong();
	}
	catch (int e)
	{
		std::cout << "Error code: " << e << std::endl;
	}
	catch (const char* e)
	{
		std::cout << "Error msg: " << e << std::endl;
	}
	catch (string &e)
	{
		std::cout << "Error string msg: " << e << std::endl;
	}

	std::cout << "Program didnt crash " << std::endl;

	return 0;
}