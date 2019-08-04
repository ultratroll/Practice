#include <iostream>
#include <string>

using namespace std;

void Test(void (*pGreet)(string), string Name)
{
	pGreet(Name);
}

int TestPlus(int (*pAdd)(int, int), int i, int j)
{
	return pAdd(i,j);
}

int main()
{
	auto Greet = [](string Name){std::cout << "Hello " << Name << std::endl;};

	Greet("Fred");

	Test(Greet, "Bob");

	auto Add = [](int i, int j){ return i+j;};
	std::cout << Add(2,3) << std::endl;

	std::cout << TestPlus(Add, 8, 7)<< std::endl;

	auto Divide = [](double A, double B) -> double  // If needed specify the double return type to help compiler understand this auto is for a double 
	{
		if (B==0)
		{
			return 0.0;
		}
		else
		{
			return A/B;
		}
		
	};

	std::cout << Divide(4,0) << std::endl;
}