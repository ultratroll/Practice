#include <iostream>
#include "ring.h"

// Using ring.h

using namespace std;

int main()
{
	ring<int>::iterator it;

	it.print();

	/*
	ring<string> Textring;

	Textring.add("one");
	Textring.add("two");
	Textring.add("three");
	Textring.add("four");

	for (int i= 0; i< Textring.size(); i++)
	{
		cout << Textring.get(i) << endl;
	}
	*/

	return 0;
}