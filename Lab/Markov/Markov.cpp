#include "Markov.h"
#include <fstream>
#include <iostream>
#include <ctime>

using namespace std;

Markov::Markov()
{}

Markov::~Markov()
{}

void Markov::CreateDictionary(string FileName, int Order)
{
	fstream textFile;

	textFile.open(FileName);

	if (!textFile)
	{
		std::cout << "File could not be open" << std::endl;
		return;
	}

	string SingleWord, Key, Suffix;
    
	int KeyCountWord = 0;
	long int pos = 0;

	// Lets create the keys
	while (textFile >> SingleWord) 
	{ 
		if (KeyCountWord == 0) 
			pos = textFile.tellp();

		KeyCountWord++;
		Key += SingleWord;
		
		if (KeyCountWord<2) 
			Key += " ";

		if (KeyCountWord >= Order)
		{
			textFile >> SingleWord;
			textFile.seekp(pos);

			// The last character is space, remove it
			if (Key.length()>0)
				Key.pop_back();

			// lets see if the suffix already exists, we dont want duplicates for the time being
			if( std::find( _dictionary[Key].begin(), _dictionary[Key].end(), SingleWord ) == _dictionary[Key].end() )
				_dictionary[Key].push_back( SingleWord );

			KeyCountWord = 0;
			Key.clear();
		}
	}

	textFile.close();
}

void Markov::PrintDictionary()
{
	std::cout << "//////////////////////////////////////////"<< std::endl;
	std::cout << _dictionary.size() << std::endl;
	for (pair<string, list<string>> pair : _dictionary)
	{
		std::cout << pair.first << " [";

		for (string nextWord : pair.second)
		{
			std::cout << nextWord << " ";
		}

		std::cout << "]"<< std::endl;
	}
	std::cout << "//////////////////////////////////////////"<< std::endl;
}

void Markov::Run(int Words)
{
	string generatedText;

	map<string, list<string>>::iterator itKeys = _dictionary.begin();
	list<string>::iterator itSeconds;

	srand(time(NULL));
	advance( itKeys, rand() % _dictionary.size() );
	string key;
	key = (*itKeys).first;
	generatedText+= key;

	while (Words > 1)
	{	
		list<string> nextWords= itKeys->second;
		itSeconds = itKeys->second.begin();

		if (nextWords.size() > 0 )
		{
			advance(itSeconds, rand() % nextWords.size());
			string second= *itSeconds;
			generatedText+= " "+ second;

			itKeys = _dictionary.find(second); 

			if (itKeys == _dictionary.end())
			{
				break;
			}
			//break;
			key = (*itKeys).first;
		}
		Words--;
	}

	std::cout << "//////////////////////////////////////////" << std::endl;
	std::cout << generatedText << std::endl;
}

int main()
{
	Markov markov;
	markov.CreateDictionary("Test.txt", 1);
	markov.PrintDictionary();
	markov.Run(40);

	return 0;
}
