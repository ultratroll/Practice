#include <iostream>
#include <vector>

using namespace std;

int main()
{

	auto Texts = {"one", "two", "three"};

	for (auto Text: Texts)
	{
		std::cout << Text << std::endl;
	}

	vector<int> Numbers;

	Numbers.push_back(4);
	Numbers.push_back(7);
	Numbers.push_back(5);
	Numbers.push_back(2);
	Numbers.push_back(3);

	for (auto Number : Numbers)
	{
		std::cout << Number << std::endl;
	}

	// Iterate trough characters
	for (auto C : "Hello")
	{
		std::cout << C << std::endl;
	}

	return 0;
}