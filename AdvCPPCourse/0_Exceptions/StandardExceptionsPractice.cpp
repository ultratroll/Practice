#include <iostream>
using namespace std;

// Ultratroll: Basic STANDARD exception examples


class CanGoWrong 
{
public:
	CanGoWrong()
	{
		// VS COMPILER DOESNT ALLOW THIS
		//char* pMemory = new char[99999999999999999999999999999999999];
		char* pMemory = new char[9];
		delete [] pMemory;

		// CHEAT !
		// Visual studio compiler actually caughts the error, but this is an example of catching the exepction when too much memory 
		// is allocated, but insane big number above is not allowed by compiler. Cheating doing by force as follows
		throw std::bad_alloc();
	}

};

int main ()
{
	// Visual studio compiler actually caughts the error, but this is an example of catching the exepction when too much memory is allocated
	try 
	{
		CanGoWrong Wrong;
	}
	catch (std::bad_alloc &e)
	{
		std::cout << "Caugh exception: " << e.what() << std::endl;
	}

	std::cout << "Program didnt crash " << std::endl;
	return 0;
}