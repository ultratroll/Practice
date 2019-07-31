// ring with lower case just for this section, a convention to easily identify the ring classes

#ifndef RING_h
#define RING_h

#include <iostream>
#include <string>

using namespace std;

template<class T>
class ring
{
public:
	class iterator;
	// A nested class !
	/*
	class iterator
	{
	public:
		void print()
		{
			cout << "Iterator !" << endl;
		}
	};*/
};

template<class T>
class ring<T>::iterator
{
public:
	void print()
	{
		cout << "Iterator ! "<< T() << endl;
	}
};

#endif