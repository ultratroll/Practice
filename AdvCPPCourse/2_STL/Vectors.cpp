#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	//vector<string> Strings(4);
	//Strings[3] = "potato";

	vector<string> Strings;

	Strings.push_back("One");
	Strings.push_back("Two");
	Strings.push_back("Three");

	for (int i= 0; i < Strings.size(); i++)
		std::cout << Strings[i] << std::endl;

	for (vector<string>::iterator it = Strings.begin(); it != Strings.end(); it++)
		std::cout << *it << std::endl;
	
	return 0;
}