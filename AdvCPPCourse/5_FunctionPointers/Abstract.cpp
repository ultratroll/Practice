#include <iostream>

using namespace std;

class Animal
{
public:
	virtual void Talk() const =0; // This is a pure virtual function, wont be implemented here

	// A class like this with pure virtual functions is called an abstract class

	// Abstract classes of course cant be instantiated
};

class Dog : public Animal
{
public:
	virtual void Talk() const // virtual is not needed here, C++ understands its a concrette implementation from the parent version
	{
		std::cout << "Woof!" << std::endl;
	}

	// When a class like this one inherits from an abstract class, it has to implement all pure virtual function from the parent, or it will be abstract as well

	// We could have this Dog class be abstract by no  implementing all pure virtual functions from Animal, but then implement all of them in a Pug class inherting from Dog
};

// We can pass by reference an abstract class
void Test(Animal& animal)
{
	animal.Talk();
}

int main()
{
	Dog doggo;
	doggo.Talk();

	// Cant create an array of animals, it will try to construct all
	//Animal Animals[5];

	// But we can create an array of pointers to Animals, since it wont try to construct those

	Animal* Animales[5];
	Animales[0] = &doggo;
	Animales[0]->Talk();

	// We can pass by reference an abstract class
	Test(doggo);

	return 0;
}