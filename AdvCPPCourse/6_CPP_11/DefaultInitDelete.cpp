#include <iostream>
#include <string>

using namespace std;

/*
	Using {} to init parameters.
 */

class Test
{
private:
	int Id{};
	string Code{"Bob"};
public:
	
	// Replaces implicit constructor that we lost
	Test() = default;

	// Requires default constructor if added, because adding this removes the implicit constructor, that we can implement ourselves or do it as above
	Test(int Id) : Id(Id)
	{}

	// this is a way of saying in C+++11, hey, we want a copy constructor
	//Test(const Test &Other) = default;

	// As alternative, delete serves to say we DONT want a copy constructor, thus, something like
	//
	// will fail to compile. Useful for example if you want forbid something from being copied
	Test(const Test &Other) = delete;

	// We can go further and do the same for assign operator 
	Test& operator=(const Test &Other) = delete;

	void Print()
	{
		std::cout << Id << "||" << Code << std::endl;
	}
};

int main()
{
	// Without constructor custom implementation this works alone
	Test Testo;
	Testo.Print();

	Test Test1(45);
	Test1.Print();

	// This wont work, we deleted the copy constructor and the assignation operator !
	//Test Test2= Testo;
	//Test2 = Test1;
	//Test2.Print();

	return 0;
}