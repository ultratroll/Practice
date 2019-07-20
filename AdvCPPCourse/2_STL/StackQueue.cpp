#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

class Cat
{

private:

	string Name;
	int Age;

public:

	Cat(string Name, int Age) : Name(Name), Age(Age)
	{}

	Cat() : Name("Gato"), Age(0)
	{}

	~Cat()
	{
		std::cout << Name << " goes to sleep" << std::endl; 
	}

	void Print() const
	{
		std::cout << "--" << Name << ", Age: " << Age << std::endl;
	}

	bool operator<(const Cat& Other) const
	{
		return Name < Other.Name;
	}
};

int main()
{
	// LIFO
	stack<Cat> Cats;

	Cats.push(Cat("Lulu", 1));
	Cats.push(Cat("Momo", 3));
	Cats.push(Cat("TD", 1));
	
	/*
	// Dont do this as follows, its invalid code
	Cat &Test2= Cats.top();
	Cats.pop(); // This will destroy it!
	Test2.Print(); // This reference points to a destroyed object
	 */

	while(Cats.size()>0)
	{
		Cat& Test = Cats.top(); // Or this way without &, for a copy, |Cat Test|, but now each iteration will destroy two cats, the copy in Test and the one being pop
		// Having |Cat& Test| only pops one each iteration
		Test.Print();
		Cats.pop();
		// Test will be destroyed at the end of this iteration
		// Log is pretty much print, destroy, over and over, for each element
	}

	/*
	Cat Test;
	while(Cats.size()>0)
	{
		Test = Cats.top();
		Test.Print();
		// Test wont be destroyed at the end of this iteration
		// Log is pretty much only printing the first element over and over
	}
	*/

/*
	Cats.top().Print();
	Cats.pop();
	Cats.top().Print();
*/

	std::cout << "------------------------------- Queue -------------------------" << std::endl;

	// FIFO
	queue<Cat> QueueCats;

	QueueCats.push(Cat("Princess Lulu", 1));
	QueueCats.push(Cat("Chairman Momo", 3));
	QueueCats.push(Cat("Lord TD", 1));

	QueueCats.front().Print(); // Front gives us whoever first arrived to the queue
	QueueCats.pop();
	QueueCats.front().Print();
	std::cout << "--- Leaving program" << std::endl;
}