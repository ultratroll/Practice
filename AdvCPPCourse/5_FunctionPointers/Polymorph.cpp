#include <iostream>
#include <string>

class Dad
{
private:
	int One;

public:

	Dad() : One(0)
	{
	}

	Dad(const Dad &Other) : One(0)
	{
		std::cout << "--Copy construct Dad" << std::endl;
	}

	virtual void Print() const
	{
		std::cout << "Parent" << std::endl;
	}

	virtual ~Dad()
	{
		std::cout << "---Dead Parent" << std::endl;;
	}
};

class Son: public Dad
{
private:
	int Two;
public:

	Son() : Two(0) // One(0) cant !, One is inaccesible since its private
	{
	}

	Son(const Son &Other)  : Two(0) // One(0) cant !, One is inaccesible since its private
	{
		std::cout << "--Copy construct Son" << std::endl;
	}

	void Print() const
	{
		std::cout << "Child" << std::endl;
	}

	virtual ~Son()
	{
		std::cout << "---Dead Son" << std::endl;
	}
};

int main()
{
	//Son Ason;
	
	//Dad& Adad= Ason;

	//Adad.Print(); 	// If Dad::Print is not virtual, compiler will resolve that this prints Parent. If its virtual, c++ is gonna create table function pointers 
					//and it will prints Child
	

	Dad P2= Son();
	P2.Print();		// Prints parent, because its threated like a Dad, because its using a default copy constructor from the Dad class

	// Beware of object slicing.....the copy constructor of the dad will copy the values of the reference argument in the previous example, each value. But
	// private member Two in the child wont be copied, the dad copy constructor wont be able to copy the value, CAREFUL when assigning child classes to 
	// parent classes for this reason, like in here 
	// Dad P2= Son();

	std::cout << "----Taking off" << std::endl;

	return 0;
}