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

	iterator begin()
	{
		return iterator(0, *this);
	}

	iterator end()
	{
		return iterator(_size, *this);
	}

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
private:
	int _position;
	ring& _ring; // Reference to the ring

public:

	iterator(int position, ring &ring): _position(position), _ring(ring)
	{
	}

	iterator& operator++()
	{
		_position++;
		return *this;
	}

	// suffix version ?
	iterator& operator++(int)
	{
		_position++;
		return *this;
	}

	T& operator*()
	{
		return _ring.get(_position);
	}
	
	bool operator!=(const iterator &other) const
	{
		return _position != other._position;
	}
};

#endif