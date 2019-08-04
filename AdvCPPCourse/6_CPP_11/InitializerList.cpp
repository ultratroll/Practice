#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>

using namespace std;

class InitTest
{
public:
	InitTest(initializer_list<string> Texts)
	{
		for (auto Text : Texts)
		{
			std::cout << Text << std::endl;
		}
	}

	void Print(initializer_list<string> Texts)
	{
		for (auto Text : Texts)
		{
			std::cout << Text << std::endl;
		}
	}
};

int main()
{
	vector<string> Texts{"Zavala","Ikora","Cayde"};

	for (auto Text : Texts)
	{
		std::cout << Text << std::endl;
	}

	InitTest Test{"Zavala","Ikora","Cayde"};

	Test.Print({"Zavala","Ikora","Cayde"});
}