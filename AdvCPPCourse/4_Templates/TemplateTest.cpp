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

	Testo.Print();

	return 0;
}