#include <iostream>

using namespace std;

// so, its weird and little porbable we are gonna need it, but to be aware
// at times references are collapsed, when the compiler infers the type with auto or templates, and what is an rvalue can be looked as an lvalue or viceversa
// in those cases, forward allows us to have the references threated correctly as rvalue or lvalue
// and using functions like check in this example is the surest way to differentitat those
// https://stackoverflow.com/questions/13725747/concise-explanation-of-reference-collapsing-rules-requested-1-a-a-2


class Test
{

};

void Check(Test& SingleTest)
{
	std::cout << "lvalue" << std::endl;
}

void Check(Test&& SingleTest)
{
	std::cout << "rvalue" << std::endl;
}
// Calls get an rvalue
template<typename T>
void Call(T&& SingleT)
{
	Check(forward<T>(SingleT)); // Check(SingleT); would resulted in an rvalue in line A, because we are passing an lvalue that somehow the rvalue reference accepts
	// forward<T>(SingleT) makes sure the inferred type is the right type, and its correctly  an lvalue as we see in line A
}

int main()
{
	Test Test1;

	Call(Test1); // LINE A, for sure an lvalue, even if it passes as an rvalue reference in Call
	Call(Test()); // LINE B, for sure an rvalue

	return 0;
}