#include <iostream>
#include <string>
#include "ring.h"

// Using ring.h

using namespace std;

int main()
{
	ring<int>::iterator it;

	it.print();

	ring<string> Textring(3);

	Textring.add("one");
	Textring.add("two");
	Textring.add("three");
	Textring.add("four");

	for (int i= 0; i< Textring.size(); i++)
	{
		cout << i << " :" << Textring.get(i) << endl;
	}

	return 0;
}