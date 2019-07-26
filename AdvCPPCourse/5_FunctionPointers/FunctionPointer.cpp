#include <iostream>
#include <string>

using namespace std;

void Test()
{
	std::cout << "Test" << std::endl;
}

void TestNumber(int N)
{
	std::cout << "Test" << N << std::endl;
}

int main()
{
	// Pointer to a void function with no arguments
	void (*pTest) ();
	pTest = &Test;
	(*pTest)();

	//But the function is already a pointer, we could simply write
	void (*pTest2) ();
	pTest2 = Test;
	pTest();

	// With arguments. And we can init it right away
	void (*pTestNum)(int) = TestNumber;
	pTestNum(8);
}