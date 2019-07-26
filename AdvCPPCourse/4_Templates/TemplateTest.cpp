#include <iostream>
#include <string>

using namespace std;

template<class T, class K>
class Test
{
private:

	T ObjA;
	K ObjB;

public:

	//Test<T,K>(): ObjA(), ObjB() // Not needed to add the types here, some people do
	Test(): ObjA(), ObjB() // Lets add the constructors for our types, so we can have this default constructor
	{
		std::cout << ObjA << "default" << ObjB << std::endl;
	}

	Test (T A, K B)
	{
		this->ObjA= A;
		this->ObjB= B;
	}

	void Print()
	{
		std::cout << ObjA << "," << ObjB << std::endl;
	}
};

int main  ()
{
	Test<string, int> Testo("Im the test", 0);

	Test<string, int> Testo2;

	Testo.Print();
	Testo2.Print();

	return 0;
}