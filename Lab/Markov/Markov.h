#ifndef MARKOV_H
#define MARKOV_H

#include <map>
#include <string>
#include <list>

using namespace std;

class Markov
{

private:

	map<string, list<string>> _dictionary;

public:

	Markov();

	~Markov();

	void CreateDictionary(string FileName, int Order);

	void PrintDictionary();

	void Run(int Words);

};

#endif // MARKOV_H