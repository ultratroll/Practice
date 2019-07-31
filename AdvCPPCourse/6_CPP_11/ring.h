// ring with lower case just for this section, a convention to easily identify the ring classes

#ifndef RING_h
#define RING_h

#include <iostream>
#include <string>

using namespace std;

template<class T>
class ring
{
private:
	T* _values; // Our array of values
	int _size;
	int _position;
public:
	ring(int size) : _values(NULL), _size(size), _position(0)
	{
		_values = new T[size];
	}

	~ring()
	{
		 delete[] _values;
	}

	int size()
	{
		return _size;
	}

	void add(T value)
	{
		_values[_position++] = value;
		//_position++;

		if (_position+1 >  _size)
		{
			_position= 0;
		}
	}

	T &get(int index)
	{
		return _values[index];
	} 

	
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