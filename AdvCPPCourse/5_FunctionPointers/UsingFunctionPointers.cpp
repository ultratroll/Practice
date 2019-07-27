#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Check(string Text)
{
	return Text.size() == 3;
}

int CustomChecker(vector<string> &Texts, bool (*CheckFunction)(string TextToCheck))
{
	int HowMany = 0;
	for (vector<string>::iterator It = Texts.begin(); It != Texts.end(); It++)
	{
		if (CheckFunction(*It))
			HowMany++;
	}

	return HowMany;
}

int main()
{
	vector<string> Texts;

	Texts.push_back("one");
	Texts.push_back("ones");
	Texts.push_back("two");
	Texts.push_back("thr");
	Texts.push_back("four");

	cout << count_if(Texts.begin(), Texts.end(),Check) << endl;


	cout << CustomChecker(Texts, Check) << endl;
}