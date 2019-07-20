#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 #pragma pack instructs the compiler to pack structure members with particular alignment. Most compilers, when you declare a struct, will insert 
 padding between members to ensure that they are aligned to appropriate addresses in memory (usually a multiple of the type's size). 
 This avoids the performance penalty (or outright error) on some architectures associated with accessing variables that are not aligned properly.
 
  For example, given 4-byte integers and the following struct: 

struct Test
{
   char AA;
   int BB;
   char CC;
};

The compiler could choose to lay the struct out in memory like this:

|   1   |   2   |   3   |   4   |  

| AA(1) | pad.................. |
| BB(1) | BB(2) | BB(3) | BB(4) | 
| CC(1) | pad.................. |

Thus why this struct will have a size of 12 bytes, even though it only contains 6 bytes of data. 

The most common use case for the #pragma is when working with hardware devices where you need to ensure that the compiler does not 
insert padding into the data and each member follows the previous one. With #pragma pack(1), the struct above would be laid out like this:

|   1   |

| AA(1) |
| BB(1) |
| BB(2) |
| BB(3) |
| BB(4) |
| CC(1) |
And sizeof(Test) would be 1 × 6 = 6.

With #pragma pack(2), the struct above would be laid out like this:

|   1   |   2   | 

| AA(1) | pad.. |
| BB(1) | BB(2) |
| BB(3) | BB(4) |
| CC(1) | pad.. |
And sizeof(Test) would be 2 × 4 = 8.

Order of variables in struct is also important. With variables ordered like following:

struct Test
{
   char AA;
   char CC;
   int BB;
};
and with #pragma pack(2), the struct would be laid out like this:

|   1   |   2   | 

| AA(1) | CC(1) |
| BB(1) | BB(2) |
| BB(3) | BB(4) |
and sizeOf(Test) would be 3 × 2 = 6.

 * */


#pragma pack(push, 1)
struct Person
{
	// we want the actual chars stored, not a pointer, thus why we dont use string
	char Name[50]; // 50 bytes
	int Age; // 4 bytes
	double Height; // 8 bytes
};
#pragma pack(pop)

int main()
{
	std::cout << "Person size: "<< sizeof(Person) << std::endl;

	Person PersonIn, PersonOut;

	PersonOut = {"Frodo", 220, 0.8};

	string FileName = "Custom.bin";

/* Writing to the binary */

	// ofstream OUTBinaryFile;
	fstream BinaryFile;

	//OUTBinaryFile.open(FileName, ios::binary); // ios::out redundant for an ofstream
	BinaryFile.open(FileName, ios::binary | ios::out); // This is more "old school" BinaryFile.open(FileName, ios::binary | ios::out);

	if (BinaryFile.is_open())
	{
		BinaryFile.write(reinterpret_cast<char*>(&PersonOut), sizeof(Person));

		BinaryFile.close();
	}
	else 
	{
		std::cout << "Could not create file " << FileName << std::endl;
	}

/* Reading from the binary */	

//OUTBinaryFile.open(FileName, ios::binary); // ios::out redundant for an ofstream
	BinaryFile.open(FileName, ios::binary | ios::in);

	if (BinaryFile.is_open())
	{
		BinaryFile.read(reinterpret_cast<char*>(&PersonIn), sizeof(Person)); // This is more "old school" BinaryFile.read((char*)&PersonIn, sizeof(Person));

		std::cout << PersonIn.Name << ", " << PersonIn.Age << ", " << PersonIn.Height << ", " << std::endl;

		BinaryFile.close();
	}
	else 
	{
		std::cout << "Could not read file " << FileName << std::endl;
	}

	return 0;
}