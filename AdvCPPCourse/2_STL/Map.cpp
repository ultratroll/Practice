#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	map<string, int> Debts;

	Debts["Mike"] = 145;
	Debts["Ana"] = 102;
	Debts["Fred"] = 87;

	const pair<string, int> NewDebt("Bob", 100);

	Debts.insert(NewDebt);

	Debts.insert(make_pair<string, int>("Bobby", 101));

	Debts.insert(make_pair("Bobbo", 104));

	if (Debts.find("Bob12") != Debts.end())
	{
		cout << "Key found" << endl;
	}
	else
	{
		cout << "Key not found" << endl;
	}
	
	cout << "-------------"<< endl;

	for (map<string, int>::iterator it = Debts.begin(); it != Debts.end(); it++)
	{
		const pair<string, int> Debt = *it;
		cout << "Key: "<< Debt.first << ", Val: " << Debt.second << endl;
	}

	cout << "-------------"<< endl;

	for (map<string, int>::iterator it = Debts.begin(); it != Debts.end(); it++)
	{
		cout << "Key: "<< it->first << ", Val: " << it->second << endl;
	}

	return 0;
}