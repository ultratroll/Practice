#include <iostream>
#include <exception>

using namespace std;

class MyException : public exception
{
	// implementation of what
	virtual const char* what() const throw()
	{
		return "exception::what : My custom exception ";
	}
};

class ClassWentWrong
{
public:
	void SomethingWrong()
	{
		throw MyException();
	}
};

// Ultratroll: custom exception examples

int main()
{

	ClassWentWrong WrongTest;

	try
	{
		WrongTest.SomethingWrong();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	std::cout << "Program didnt crash" << std::endl;
	return 0;
}