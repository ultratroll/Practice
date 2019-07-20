#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main ()
{
	string FileName = "Test.txt";

	ifstream InFile;

	InFile.open(FileName);

	// lines
	if (InFile.is_open())
	{
		while (!InFile.eof()) // while (InFile) also works, overloaded operator
		{
			string Line;
			//Line << InFile;
			getline(InFile, Line);
			std::cout << ". "<< Line << std::endl;
		}
		InFile.close();
	}
	else
	{
		std::cout << "Cant open " << FileName << std::endl;
	}

	InFile.open(FileName);

	// words
	if (InFile.is_open())
	{
		while (!InFile.eof())
		{
			string Word;
			InFile >> Word;
			std::cout << ".. "<< Word << std::endl;
		}
		InFile.close();
	}
	else
	{
		std::cout << "Cant open " << FileName << std::endl;
	}
	

	return 0;
}