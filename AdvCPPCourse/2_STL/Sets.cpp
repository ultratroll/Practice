#include <iostream>
#include <set>
#include <string>

using namespace std;

class TechnoRelic
{

private:
	int Antiquity;
	std::string ImperiumName;

public:

	TechnoRelic(): Antiquity(0), ImperiumName("Artifact")
	{
	}

	TechnoRelic(int Age, string Name): Antiquity(Age), ImperiumName(Name)
	{
	}

	// When we iterate trough the set, objects are const, so we need to amke sure our print method is marked as const
	void Print() const
	{
		std::cout << " Antiquity: " << Antiquity << " Imperium Name: " << ImperiumName << std::endl;  
	}

	// The set is gonna compare for uniqune, so we need to write this operator for this to function as we expect
	bool operator<(const TechnoRelic& Relic) const
	{
		if (ImperiumName != Relic.ImperiumName)
			return ImperiumName < Relic.ImperiumName;
		else
			return Antiquity < Relic.Antiquity;
	}

};

int main()
{
	set<int> Parts;

	Parts.insert(47);
	Parts.insert(47);
	Parts.insert(48);
	Parts.insert(6);

	for (set<int>::iterator it = Parts.begin(); it != Parts.end(); it++)
	{
		std::cout << "Part value " << *it << std::endl;
	}

	// find

	set<int>::iterator ItFind = Parts.find(47);

	if (ItFind != Parts.end())
	{
		std::cout << "Found : " << *ItFind<< endl;
	}

	// count
	if (Parts.count(47))
	{
		std::cout << "There is a 47 " << endl;
	}

	std::cout << "----------------------------------------" << endl;

	set<TechnoRelic> Relics;

	Relics.insert(TechnoRelic(125, "Papnotic Mirror"));
	Relics.insert(TechnoRelic(125, "Sol Ring"));
	Relics.insert(TechnoRelic(125, "Snaring Bridge"));
	Relics.insert(TechnoRelic(30, "Sol Ring"));
	Relics.insert(TechnoRelic(125, "Papnotic Mirror"));

	for (set<TechnoRelic>::iterator it = Relics.begin(); it != Relics.end(); it++)
	{
		it->Print();
	}

	return 0;
}