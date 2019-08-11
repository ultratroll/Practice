#include <iostream>

using namespace std;

class Parent
{
public:
	void Speak()
	{
		std::cout << "Hi im a parent" << std::endl;
	}

	virtual ~Parent()
	{}
};

class Brother : public Parent
{
public:
void Speak()
	{
		std::cout << "Hi im a brother" << std::endl;
	}
};

class Sister : public Parent
{
public:
void Speak()
	{
		std::cout << "Hi im a sister" << std::endl;
	}
};

int main()
{
	Brother Brother1;
	Parent  Parent1;

	// STATIC CAST, done at compile time, and allowing some odd situations to happen, unsafe if not VERY careful when using it

	//Brother *pBrother = &Parent1; // Ilegal
	//Brother *pBrother = static_cast<Brother*>(&Parent1); // Warning, This works but its very insecure, try to call brother method and will probably crash

	Parent *pParent= &Brother1; // Works thanks to polymorphism
	Brother *pBrother = static_cast<Brother*>(pParent); // Just Brother *pBrother = pParent; doesnt work, but since in this case we KNOW pParent points to a brother (see prev line) its a 
	// case where static casting is useful and not that dangerous

	// static_cast is compile time and pretty dangerous when used without care

	std::cout << pBrother << std::endl;

	Parent&& pParentRValue= static_cast<Parent&&>(Parent1); // Used to disguise a lvalue parent as a reference to a right value parent !, if you REALLY need to !
	pParentRValue.Speak();


	// DYNAMIC CAST actually checks at runtime
	// So , we can do stuff like this but its dangerous, there is no garantee pParent actually points to a brother
	//Parent *pParent= &Brother1; // Works thanks to polymorphism
	//Brother *pBrother = static_cast<Brother*>(pParent); // Just Brother *pBrother = pParent; doesnt work, but since in this case we KNOW pParent points to a brother (see prev line) its a 
	
	Parent *pParent1= &Parent1; // Works thanks to polymorphism
	Brother *pBrotherDyn = dynamic_cast<Brother*>(pParent1); // HAD to add a virtual method to parent. Otherwise, not a polymorphic class for the compiler and dynamic_cast wont
	// work

	if (pBrotherDyn== nullptr)
	{
		std::cout<< "Invalid cast " << std::endl; // Nice, dynamic_cast catchs its an invalid cast to Brother*
	}
	else
	{
		std::cout<< "good cast " << pBrotherDyn << std::endl;
	}

	// And now if we make pParent point to an actual brother
	pParent1= &Brother1;
	pBrotherDyn = dynamic_cast<Brother*>(pParent1);
	
	if (pBrotherDyn== nullptr)
	{
		std::cout<< "Invalid cast " << std::endl; 
	}
	else
	{
		std::cout<< "good cast " << pBrotherDyn << std::endl; // Success
	}

	// REINTERPRET CAST for last, it cast anything into anything by force, is even less secure than static cast and does less validation than it
	// pBrotherDyn = reinterpret_cast<Brother*>(pParent1);
	// use it under your own responsability

	return 0;
}