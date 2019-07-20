#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// Simple nested example

int main()
{
	map<string, vector<int> > Leaderboard;

	Leaderboard["Ed"].push_back(45);
	Leaderboard["Ed"].push_back(47);
	Leaderboard["Ed"].push_back(15);
	Leaderboard["Ed"].push_back(28);

	Leaderboard["Xx"].push_back(28);
	Leaderboard["Xx"].push_back(97);
	Leaderboard["Xx"].push_back(14);

	for (map<string, vector<int> >::iterator It = Leaderboard.begin(); It != Leaderboard.end(); It++)
	{
		string Name= It->first;
		vector<int> Scores = It->second;

		std::cout<< "Score for : " << Name << " | "<< flush;

		for (int i= 0; i < Scores.size() ; i++)
		{
			std::cout<< i << " --" << Scores[i] << " | "<< flush;
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	return 0;
}