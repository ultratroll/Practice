#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Test
{
private:

	static const int SIZE= 100;
	int * _pBuffer{nullptr}; // Initialize the pointer to nullptr, has nothing to do with the values inside the space reserved, just making _pBuffer a null pointer

public:
	Test()
	{
		_pBuffer = new int[SIZE]{}; // Allocate our buffer
	}

	Test(Test &Other)
	{
		_pBuffer = new int[SIZE]{}; // Allocate our buffer
		memcpy(_pBuffer, Other._pBuffer, SIZE * sizeof(int) ); // Lets copy the buffer
	}

	// Moving constructor!
	Test(Test &&Other)
	{
		std::cout << "Move constructor" << std::endl;

		//_pBuffer = new int[SIZE]{};
		// We dont need to allocate the buffer, we are gonna steal it from the rvalue
		_pBuffer = Other._pBuffer; // This moving constructor is gonna steal from the puny and weak rvalue which was gonna die anyway

		// The trick here is that Other is gonna be destroyed, and its destructor is gonna take this buffer with it. So we make sure that other points to null, nothing will happen
		// when tis deleted and the buffer of this instance will be around even if other is destroyed. 

		// Its literally stealing the buffer from the rvalue!
		// Safe for mem leaks, remember we taken the other buffer for ourselves and nothing will happen when the other rvalue is destroyed
		Other._pBuffer= nullptr;

		memcpy(_pBuffer, Other._pBuffer, SIZE* sizeof(int));
	}

	Test(int i)
	{
		_pBuffer = new int[SIZE]{};

		for (int j=0; j < SIZE; j++)
			_pBuffer[j] = i;
	}

	~Test()
	{
		delete[] _pBuffer; // Delete the buffer
	}

	Test &operator=(const Test &Other)
	{
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
	vector<Test> VectorTest;
	VectorTest.push_back(Test()); 
	// This will automatically use the move constructor since Test() si an rvalue (if there was no move constructor it would probably 
	//use the copy constructor as usual)

	// move constructor is pretty efficient, it doesnt allocate more memory, it steals from the soon to die  rvalue

	return 0;
}