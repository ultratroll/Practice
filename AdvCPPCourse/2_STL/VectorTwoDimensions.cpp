#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// Grid with three rows, each with four columns initated at 7
	vector< vector<int> > Grid(3, vector<int>(4,7));

	//Grid[1].push_back(8);

	for (int i= 0 ; i < Grid.size(); i++)
	{
		for (int j= 0 ; j < Grid[i].size(); j++)
		{
			cout << Grid[i][j] << flush;
		}
		cout << endl;
	}

	return 0;
}