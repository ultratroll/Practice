#include <iostream>
#include <map>
#include <string>

using namespace std;

class Technomancer
{

private:

	string Designation;
	int Age;
	int Power;

public:

	// The default constructor is needed for the map to work with it, the next constructor after this is not enough
	Technomancer():Designation(""), Age(0), Power(0)
	{		
	} 

	Technomancer(string MyDesignation, int MyAge, int MyPower):Designation(MyDesignation), Age(MyAge), Power(MyPower) 
	{
	}

	// a copy constructor
	Technomancer(const Technomancer &Other)
	{
		cout << "Using a copy constructor" << endl;

		Designation = Other.Designation;
		Age = Other.Age;
		Power = Other.Power;
	}

	// If we use thus ckass as keys for the map, its important to have it be const. Since keys are const, we are not gonna chnage them
	void Print() const
	{
		cout << " Designation: " << Designation << " Age: " << Age << " Power: " << Power << flush;
	}

	// To use this class as keys on the maps it needs a way to compare. Const is important for it to work.
	bool operator<(const Technomancer &Other) const
	{
		// If same power use age as criteria
		if (Power == Other.Power)
			return Age < Other.Age;
		else
		{
			return Power < Other.Power;
		}
		
	}

	bool operator==(const Technomancer &Other) const
	{
		return Designation == Other.Designation && Age == Other.Age && Power == Other.Power;
	}

};

void CustomObjectsTest()
{
	map<int, Technomancer> Technomancers;

	// By default the assignation operator here actually uses the default constructor and then assigns those values, a shallow copy, rather than using our other constructor 
	// with arguments but is some are pointers, we dont actually want to copy those
	Technomancers[0] = Technomancer("Bob", 512, 1024); 
	Technomancers[1] = Technomancer("Barb", 549, 1048);
	Technomancers[2] = Technomancer("Beth", 1512, 2048);

	// Previous ones dont use the copy constructor

	// This way does. And using our coppy constructor we enssure we have direct control over how the copy is done
	Technomancers.insert(make_pair(17, Technomancer("Boba", 23, 26)));

	for (map<int, Technomancer>::iterator it = Technomancers.begin(); it != Technomancers.end(); it++)
	{
		it->second.Print();
	}
}

void CustomKeysTest()
{
	map<Technomancer, int> Technomancers;

	Technomancers[Technomancer("Bob", 512, 1024)] = 512;
	Technomancers[Technomancer("Boba", 40, 1024)] = 40;
	Technomancers[Technomancer("Bobtx", 900, 1024)] = 900;

	for (map<Technomancer, int>::iterator it = Technomancers.begin(); it != Technomancers.end(); it++)
	{
		it->first.Print();
		cout << endl << "|"<< it->second<< endl;
	}
}

int main()
{
	//CustomObjectsTest();
	CustomKeysTest();

	return 0;
}
