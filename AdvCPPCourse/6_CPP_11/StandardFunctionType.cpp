#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

// Standard fucntion type and also mutable lambdas

bool Check(const string &Text)
{
	return Text.size() == 3;
}

class Test
{
public:
	bool operator()(const string &Text)
	{
		return Text.size() == 3;
	}
} CheckFunctor;

// Here using the functional type
void run(function<bool(string&)> Check )
{
	string test= "Sta";
	std::cout << "Functional type test " << Check(test) << std::endl;
}

int main()
{
	vector<string> VectTest{"One", "Two", "Three"};

	int Size= 3;

	auto LambdaExp= [Size](const string &Text){ return Text.size() == Size; };

	std:: cout << "With lambda "<< count_if(VectTest.begin(), VectTest.end(), LambdaExp) << std::endl;

	std:: cout << "With function "<< count_if(VectTest.begin(), VectTest.end(), Check) << std::endl;

	std:: cout << "With class functor "<< count_if(VectTest.begin(), VectTest.end(), CheckFunctor) << std::endl;

	// Testing our function with an standard functional type
	run(Check);
	run(LambdaExp);
	run(CheckFunctor);

	function<int(int, int)>Add = [](int One, int Two) { return One+Two;};

	std::cout << Add(3,7) << std::endl; 


	// Also, since its pretty small, mutable lambdas
	// The keyword mutable simply allows the lambda expression to modify the argument passed by value inside the expression (of course, its not passing the original 
	// variable by reference, that one wont change)
	int Cats= 5;
	[Cats]() mutable
	{
		Cats= 7; // Without the mutable keyword above this asignation wont be allowed
		std::cout << Cats << std::endl;
	}();

	std::cout << "Original cats unchanged " << Cats << std::endl;

	return 0;
}
