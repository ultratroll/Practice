#include <iostream>
#include <string>

using namespace std;


class Test
{
public:
	Test()
	{
		std::cout << "Default constructor" << std::endl;
	}

	Test(Test &Other)
	{
		std::cout << "Copy constructor" << std::endl;
	}

	Test(int i)
	{
		std::cout << "Argument constructor" << std::endl;
	}

	~Test()
	{
		std::cout << "Destructor" << std::endl;
	}

	Test &operator=(const Test &Other)
	{
		std::cout << "Assignment" << std::endl;
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