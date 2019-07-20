#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	//ofstream outFile;
	fstream outFile;

	string FileName = "Test.txt";

	//outFile.open(FileName);
	outFile.open(FileName, ios::out);

	if (outFile.is_open())
	{
		outFile << "Test line 1" << std::endl;
		outFile << "Test line 2" << std::endl;
		outFile.close();
	}
	else
	{
		std::cout << "Cant open file " << FileName << std::endl; 
	}
	

	return 0;
}