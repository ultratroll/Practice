#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> Numbers;

	Numbers.push_back(0);
	Numbers.push_back(2);
	Numbers.push_back(3);
	Numbers.push_back(8);
	Numbers.push_back(12);

	/*
	list<int>::iterator It = Numbers.begin();

	It++;

	cout << "Number test: " << *It <<  endl;

	list<int>::iterator eraseIt = Numbers.begin();
	eraseIt++;

	// When you erase using an iterator, the iterator can end up  poinitng to anywhere, so its a good idea to assign it  this way sinse erase returns a new iterator
	eraseIt = Numbers.erase(eraseIt);
	*/

	for (list<int>::iterator it = Numbers.begin(); it != Numbers.end() ;)
	{
		// This can be done  while iterating trough the list without skipping elements
		if (*it == 2)
			Numbers.insert(it, 1234); // Insert at the iterator position, wont replace other members of the list

		// This cant be done  while iterating trough the list without skipping elements, it will jump one element once we erase, so we can either decrease the iterator, or
		// do it like here where we dont increment the iterator in the for but here, whenever we dont erase!
		if (*it == 8)
		{
			it = Numbers.erase(it); // Insert at the iterator position, wont replace other members of the list
			//it--; If we wanted to leave the it++ in the loop definition
		}
		else
		{
			it++;
		}
		
	}

	for (list<int>::iterator it = Numbers.begin(); it != Numbers.end() ; it++)
		cout << "Number: " << *it <<  endl;

	return 0;
}