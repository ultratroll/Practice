#include "ComplexTest.h"

namespace Practice
{

/*
*	If this is a member function is because member functions are passed an extra argument, which is a pointer to the object the member function was called on. 
*	So you have a + operator which takes three arguments but the language only allows two arguments. So its recomended to define the plus operator outside the class
*	The general thing is to have operators as member of the class when they modify the left member, like asignation
*/
ComplexTest operator+(const ComplexTest& A, const ComplexTest& B)
{
	return ComplexTest(A.GetReal()+B.GetReal(), A.Getimaginary()+B.Getimaginary());
}

ostream& operator<<(ostream& Out, const ComplexTest& Other)
{
	return Out << "(" << Other.GetReal() << ", " << Other.Getimaginary() << ") ";
}

ComplexTest::ComplexTest(): Real(0), Imaginary(0)
{
}

ComplexTest::ComplexTest(double Real, double Imaginary): Real(Real), Imaginary(Imaginary)
{
}

ComplexTest::ComplexTest(const ComplexTest& Other)
{
	std::cout<<"Using Copy constructor"<<std::endl;
	Real= Other.Real;
	Imaginary = Other.Imaginary;
}

ComplexTest& ComplexTest::operator=(const ComplexTest& ComplexNumber)
{
	std::cout<<"Using assign"<<std::endl;

	Real = ComplexNumber.Real;
	Imaginary = ComplexNumber.Imaginary;
	
	return *this;
}

// This works, but only when operating exclusvely bettwen ComplexTest
//ComplexTest ComplexTest::operator+(const ComplexTest& Other)
//{
//	return ComplexTest(Real+Other.Real, Imaginary+Other.Imaginary);
//}

bool ComplexTest::operator==(const ComplexTest& Other)
{
	return Real== Other.Real && Imaginary==Other.Imaginary;
}

bool ComplexTest::operator!=(const ComplexTest& Other)
{
	return !(*this==Other);
}

ComplexTest ComplexTest::operator*()
{
	return ComplexTest(Real, -Imaginary);
}

}

using namespace Practice;

int main()
{
	ComplexTest Test1(1,2);

	// Using copy constructor
	ComplexTest Test2= Test1;

	ComplexTest Test3;

	Test3 = Test2;

	Test3= Test3+Test2+Test1;

	std::cout << Test1 << Test2 << Test3 << std::endl;

	if (Test1==Test2)
		std::cout << "both are equal!"<<std::endl;

	if (Test1!=Test3)
		std::cout << "both are different!"<<std::endl;

	// Test of overriten * operator, in complex numbers it flips the sign of the imaginary number
	ComplexTest C1(2,4);

	std::cout<< *C1 + *ComplexTest(4,3) << endl;

	return 0;
}
