#include <iostream>
#include <string>

/** Representation fo an imaginary number. */

using namespace std;

namespace Practice
{


class ComplexTest
{
private:
	double Real;
	double Imaginary;

public:
	ComplexTest();
	ComplexTest(double Real, double Imaginary);
	ComplexTest(const ComplexTest& Other);

	double GetReal() const { return Real; }
	double Getimaginary() const { return Imaginary; }

	ComplexTest& operator=(const ComplexTest& ComplexNumber);
	// ComplexTest operator+(const ComplexTest& Other); // This works, but only when operating exclusvely bettwen ComplexTest, see explanation later
	bool operator==(const ComplexTest& Other);
	bool operator!=(const ComplexTest& Other);
	ComplexTest operator*(); // * over an imaginary number flips the sign, lets override the derreference operator !

	friend ostream& operator<<(ostream& Out, const ComplexTest& Other);
};

/*
*	If this is a member function is because member functions are passed an extra argument, which is a pointer to the object the member function was called on. 
*	So you have a + operator which takes three arguments but the language only allows two arguments. So its recomended to define the plus operator outside the class
*	The general thing is to have operators as member of the class when they modify the left member, like asignation
*/
ComplexTest operator+(const ComplexTest& A, const ComplexTest& B);

// Solved, see this explanation, the problem is that it will give incorrect behavooirs in many cases, so the best approach is to have the plus outside if 
// its gonna be used in ways like operating with other non complexTest
/*
Hi, generally it's good practice to keep all the code for a class inside the class if you can.

For the plus operator, this can be a bit tricky. Let's remind ourselves what it does:

Complex a, b;
...
a + b; // Resolved by compiler to a.operator +(b);
If a is a Complex object, the compiler will just call its overloaded plus operator. It doesn't matter here whether the operator is inside or outside the class. However, if a is a double

Complex b;
...
2.0 + b; // Resolved by compiler to (2.0).operator +(b);
the compiler can't call a member function, because double doesn't have an overloaded plus operator that takes a Complex argument, and we can't add one because double is part of the core language, which we're not allowed to change. The only solution is to add a global operator (i.e., one outside the class).

Complex b;
...
2.0 + b; // Resolved by compiler to operator +(2.0, b);
 */

}