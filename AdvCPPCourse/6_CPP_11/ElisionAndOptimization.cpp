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

		
		// Now, So, lets make sure to clean all bytes in that allocated space

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

void Check(Test &Test)
{
	std::cout<< "l-value !" <<std::endl;
}

void Check(Test &&Test)
{
	std::cout<< "r-value !" <<std::endl;
}

int main()
{
	// C++11 by default does default value optimization, Elision optimization, Compiler spots this situation (copy constructor and a function that returns an object by copy) 
	// and avoids doing a bunch of extra copies
	Test Test1 = GetTest();

	Test TestCopy= Test1;

	std::cout << Test1 << std::endl;

	// Now, L-values and R-values.
	
	// An lvalue (locator value) represents an object that occupies some identifiable location in memory (i.e. has an address).

	// rvalues are defined by exclusion, by saying that every expression is either an lvalue or an rvalue. Therefore, from the above definition of lvalue, an rvalue 
	// is an expression that does not represent an object occupying some identifiable location in memory.

	// An assignment expects an lvalue as its left operand
	//4 = var;       // ERROR!
	//(var + 1) = 4; // ERROR!
	//Neither the constant 4, nor the expression var + 1 are lvalues (which makes them rvalues). They're not lvalues because both are temporary results of expressions, which 
	//don't have an identifiable memory location (i.e. they can just reside in some temporary register for the duration of the computation). Therefore, assigning to them 
	//makes no semantic sense - there's nowhere to assign to.
	
	int Value1= 7;
	int *pValue1= &Value1;
	//int *pValue1= &8; // ERROR

	Test *pTest1= &Test1;
	//Test *pTest2= &GetTest(); // NOP, this works as the following print shows, but GetTest() result is not an lvalue, could be an optimization, but avoid
	//std::cout << "-- "<< *pTest2 << std::endl;

	int *pValue3 = &++Value1; // This applies ++ prefix to Value1, and then the adress is obtained. Success. 
	//int *pValue4 = &Value1++; // This applies ++ suffix to Value1, but Value1++ is NOT AN lvalue, its an expression, and fails upon trying &. 
	std::cout << *pValue3 << std::endl; // This will print 8
	std::cout << Value1 << std::endl; // This will print 8, remember ++Value1 above 

	// More about lvalues
	// lvalue references

	// --------- LVALUE REFERENCES
	Test Test2 = GetTest();
	Test &rTest2 = Test2;

	// REFERENCE FOR THE RVALUE RETURNED FROM GetTest
	// const reference can point to rvalues...look
	//Test &rTest3 = GetTest(); // Works, but not adviced
	const Test &rTest3 = GetTest(); // works as well, but the adviced way. lIFETIME OF THE rVALUE RETURNED BY THIS FUNCTION GETS EXTENDED
	// As long as the reference  rTest3 exists, then object return from GetTest() will exist as well

	// This will use directly the copy constructor for Test3, , here Test(1) would be an Rvalue, which we can pass to the copy constructor
	Test Test3(Test(1));

	// --------- RVALUE REFERENCES

	// This is NOT an reference to a reference or anything like that, this is how an Rvalue reference is written
	Test && rRValueTest = Test();

	//Test && rRValueTest2 = Test1; // ERROR because an rvalue reference can only reference an rvalue, Test1 is a left value
	Test && rRValueTest2 = GetTest(); // works because an rvalue reference can only reference an rvalue, GetTest() returns an rvalue 

	std::cout << "Checking .." << std::endl;
	// For show, see the two versions of Check for lvalue and rvalues, and the results
	Check(Test1); // l value
	Check(Test()); // r value
	Check(GetTest()); // r value

	return 0;
}