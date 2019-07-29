#include <iostream>
#include <typeinfo>
#include <string>

using namespace std;

int main()
{
	string Test;

	decltype(Test) Other= "bob"; // decltype(Test) would be Test type, string

	std::cout << Other << std::endl;

	std::cout << typeid(Other).name() << std::endl;


	return 0;
}
