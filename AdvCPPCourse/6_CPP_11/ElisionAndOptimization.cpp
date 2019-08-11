#include <iostream>
#include <string>

using namespace std;


class Test
{
private:

	static const int SIZE= 100;
	int * _pBuffer;

public:
	Test()
	{
		std::cout << "Default constructor" << std::endl;

		
		// So, lets make sure to clean all bytes in that allocated space

		// Test A, old school, a little bit prone to errors if making any mistake here
		//_pBuffer = new int[SIZE]; // Allocate our buffer
		//memset(_pBuffer, 0 , sizeof(int) * SIZE); // THIS WILL SET ALL BYTES TO ZERO

		// Test B, C++11, using {} makes sure to reset all the mem space there
		_pBuffer = new int[SIZE]{}; // Allocate our buffer
	}

	Test(Test &Other)
	{
		std::cout << "Copy constructor" << std::endl;

		_pBuffer = new int[SIZE]{}; // Allocate our buffer
		memcpy(_pBuffer, Other._pBuffer, SIZE * sizeof(int) ); // Lets copy the buffer
	}

	Test(int i)
	{
		std::cout << "Argument constructor" << std::endl;

		_pBuffer = new int[SIZE]{};

		for (int j=0; j < SIZE; j++)
			_pBuffer[j] = i;
	}

	~Test()
	{
		delete[] _pBuffer; // Delete the buffer
		std::cout << "Destructor" << std::endl;
	}

	Test &operator=(const Test &Other)
	{
		std::cout << "Assignment" << std::endl;

		_pBuffer = new int[SIZE]{}; // Allocate our buffer
		memcpy(_pBuffer, Other._pBuffer, SIZE * sizeof(int) ); // Lets copy the buffer

		return *this;
	}

	friend ostream &operator<<(ostream &Out, const Test &Other);
};

ostream &operator<<(ostream &Out, const Test &Other)
{
	return Out << "Test";
}

Test GetTest()
{
	return Test();
}

int main()
{
	// C++11 by default does default value optimization, Elision optimization, Compiler spots this situation (copy constructor and a function that returns an object by copy) 
	// and avoids doing a bunch of extra copies
	Test Test1 = GetTest();

	std::cout << Test1 << std::endl;
	
	return 0;
}