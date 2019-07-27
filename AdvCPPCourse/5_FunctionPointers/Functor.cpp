#include <iostream>
#include <string>

using namespace std;

/* A functor is just an struct with the () overloaded to use it like a function and pass it around */

struct FTest
{
	virtual bool operator()(string &Text)=0;
};

// Out functor
struct FMatchTest : public FTest
{
	bool operator()(string &Text)
	{
		return Text == "match";
	}
};

void Check(string &Text, FTest& Test)
{
	if (Test(Text))
		cout << "Match found";
	else
		cout << "No Match";
}

int main()
{
	FMatchTest Match1;

	string Value = "match";

	cout << Match1(Value) << endl;

	Check(Value, Match1);

	return 0;
}