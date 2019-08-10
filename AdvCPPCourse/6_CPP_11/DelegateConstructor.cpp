#include <iostream>

using namespace std;

class Dad
{
	string Id{"X3"};
	int Cats{3};

public:

	Dad() : Dad("Test") // Delegate constructor
	{
		std::cout << "Default constructor" << std::endl;
	}

	Dad(string NewId): Id(NewId)
	{
		std::cout << "Argument constructor" << std::endl;
	}
};

class Son : public Dad
{
public:
	Son() = default; // We can only use the defaul because we have not implemented anyu custom constructor in Son
};

int main()
{
	Son Kid; // Calls Dad argument and default constructor
	return 0;
}