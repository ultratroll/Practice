#include <iostream>
#include <string>

using namespace std;

class Aguacate
{
	string NameID;
	int Softness;
	int Size;

public:

	Aguacate():NameID("Yum"), Softness(1), Size(1)
	{
	}

	Aguacate(string Name, int Softness,int Size):NameID(Name), Softness(Softness), Size(Size)
	{
	}

	// Copy constructor
	Aguacate(Aguacate& Other)
	{
		std::cout << "Copy constructor" << std::endl;
		NameID = Other.NameID+ "_clone";
		Softness = Other.Softness;
		Size = Other.Size;
	}

	void Print()
	{
		std::cout << "| NameID: " << NameID << "| Softness: " << Softness << "| Size: " << Size << std::endl;
	}

	// Overwrite assignment operator. Returns the object by reference
	Aguacate& operator=(const Aguacate& Other)
	{
		std::cout << "Assignment" << std::endl;
		NameID = Other.NameID+ "_copy";
		Softness = Other.Softness;
		Size = Other.Size;

		//this->NameID;
	
		return *this; // Lets derreference this object, we want to return the actual object, not its adress
	}

	// Overriting <<. This operator is left associative.
	// Important, we should have the friend with its signature in the header file | friend ostream& operator<<(ostream& Out, const Aguacate& Other);
	// and the implementation like normal in the cpp
	// Doing it this way just for simplicity
	friend ostream& operator<<(ostream& Out, const Aguacate& Other)
	{
		return Out << "| NameID: " << Other.NameID << "| Softness: " << Other.Softness << "| Size: " << Other.Size << std::endl;
	}

};

int main()
{
	Aguacate Aguacate1("Small", 3, 1); 
	Aguacate1.Print();

	Aguacate Aguacate2;

	/* 
	*	This WITHOUT the overritten assignment operator will make a shalow copy for us, gonna copy all the parameters from Aguacate1 into Aguacate2 
	*	but at times is a bad idea, like when the class has an Id its supossed to be unique, or when we rather alloc its own memory for some parameter. In 
	*	those cases we can override the asignment operator
	*/
	Aguacate2= Aguacate1;

	// Also, previous line is the same as calling
	//Aguacate2.operator=(Aguacate1);

	Aguacate2.Print();

	/* 
	*	This WITHOUT the copy constructor, WONT run the assignment operator..and would look EXACTLY as Aguacate1, Id and everything.
	*	This is a COPY intialization;
	*/
	Aguacate Aguacate3 = Aguacate1;
	Aguacate3.Print();
	
	std::cout << Aguacate3 << std::endl;

	return 0;
}