#include <iostream>

using namespace std;

// the use of auto here doesnrt make really sense
auto Test() // -> int // Optional it seems, didnt need it
{
	return 7;
}


// But with template functions can be useful
template<class T>
auto TemplateTest(T Value) // ->decltype(Value) // If needed, to help auto figure out return type
{
	return Value;
}


template<class T, class S>
auto TemplateTest2(T Value, S Value2) ->decltype(Value+Value2) // ->decltype( can receive expressions
{
	return Value+Value2;
}

int Get() {
	return 9000;
}

auto TemplateTest3() ->decltype(Get()) // ->decltype( can receive functions
{
	return Get();
}

int main()
{

	auto value= 7; // Auto serves to "guess" the type

	std::cout << value << std::endl;

	std::cout << Test() << std::endl;

	std::cout << TemplateTest("Test with template") << std::endl;

	std::cout << TemplateTest2(5,6) << std::endl;

	std::cout << TemplateTest3() << std::endl;

	return 0;
}