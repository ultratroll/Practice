#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Aguacate
{
	int Softness;
	int Size;

public:

	Aguacate(): Softness(1), Size(1)
	{}

	Aguacate(int Softness, int Size): Softness(Softness), Size(Size)
	{}

	void Print() const
	{
		std::cout << "Aguacatico softness " << Softness << " size " << Size << std::endl;
	}

	bool operator<(const Aguacate& Other) const
	{
		if (Softness != Other.Softness)
			return Softness < Other.Softness;
		else
			return Size < Other.Size;
	}

	// The friend keyword pretty much says, ifthere is a method with this signature trying to use private members, im gonna allow it
	friend bool Compare(const Aguacate& A, const Aguacate& B);
};

bool Compare(const Aguacate& A, const Aguacate& B)
{
		if (A.Softness != B.Softness)
			return A.Softness < B.Softness;
		else
			return A.Size < B.Size;
}

int main()
{
	vector<Aguacate> Aguacates;

	Aguacates.push_back(Aguacate(1,3));
	Aguacates.push_back(Aguacate(4,3));
	Aguacates.push_back(Aguacate(2,3));
	Aguacates.push_back(Aguacate(5,3));

	for (vector<Aguacate>::iterator It = Aguacates.begin(); It != Aguacates.end();It++)
	{
		It->Print();
	}
	std::cout << "------------------------------------------------------------" << std::endl;

	//sort(Aguacates.begin(), Aguacates.end());
	sort(Aguacates.begin(), Aguacates.end(), Compare);

	for (vector<Aguacate>::iterator It = Aguacates.begin(); It != Aguacates.end();It++)
	{
		It->Print();
	}
	std::cout << "------------------------------------------------------------" << std::endl;

	return 0;
}