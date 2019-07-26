#include <iostream>

using namespace std;

template<class T>
void Print(T N) // CPP infers the type from the argument list
{
	std::cout << "Template version "  << N << std::endl;
}

void Print(int N)
{
	std::cout << "No template version " << N << std::endl;
}


template<class T>
void Show() // CPP cant infers the type from the argument list, no argument
{
	std::cout << "Show: "<< T()  << std::endl;
}


int main()
{
	Print("Aguacate");
	Print<int>(5);
	Print(5);
	Print<>(6);

	//Show(7); // Type cant be inferred, error
	Show<float>();

	return 0;
}