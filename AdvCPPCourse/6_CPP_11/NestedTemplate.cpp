#include <iostream>
#include <string>
#include "ring.h"

// Using ring.h

using namespace std;

int main()
{
	ring<string> Textring(3);

	Textring.add("one");
	Textring.add("two");
	Textring.add("three");
	Textring.add("four");

	for (int i= 0; i< Textring.size(); i++)
	{
		cout << i << " :" << Textring.get(i) << endl;
	}
	
	cout << "---------"<< endl;
	// C++98 style
	for (ring<string>::iterator it= Textring.begin(); it != Textring.end(); it++)
	{
		cout << *it << endl;
	}
	cout << "---------"<< endl;

	// C++11 style, this needs iterator implementation with all its operators to work
	for (auto Text : Textring)
	{
		cout << Text << endl;
	}

	return 0;
}