#include <iostream>
#include <memory>

using namespace std;

class Test
{
public:
	Test()
	{
		std::cout << "Created" << std::endl;
	}

	~Test()
	{
		std::cout << "Destroyed" << std::endl;
	}

	void Talk()
	{
		std::cout << "Im a test" << std::endl;
	}
};


class Temp
{
private:
	unique_ptr<Test[]> TestPointer;

	Test* TestOldPointer;

public:

	Temp(): TestPointer(new Test[3]), TestOldPointer(new Test[3])
	{}

	~Temp()
	{
		delete[] TestOldPointer; // TestOldPointer is not smart, if you dont delete it manually here, it will leak

		// Output without leak
		/**
		 * 	Created
			Created
			Created
			Created
			Created
			Finished
			Destroyed
			Destroyed
			Destroyed
			Destroyed
			Destroyed
			Destroyed
		 */

		// Output with leak if we dont delete TestOldPointer
		/**
		 * 	Created
			Created
			Created
			Created
			Created
			Finished
			Destroyed
			Destroyed
			Destroyed
		 */
	}
};

int main()
{
	// an unique_ptr is an smart pointer makes sure to destroy its content when it leaves scope. In this example, when the variable temp
	// gets off scope, all the Tests in its private array will get deleted 
	// so we dont need to delete it in the destroyer

	Temp temp;

	std::cout << "Finished-----" << std::endl;

	// And this is a small example of usage
	unique_ptr<Test> pTest(new Test); // We must allocate our pointer as shown here
	pTest->Talk();

	unique_ptr<int> pInt(new int);
	*pInt = 8; // behaves and can be used like any other regular pointer
	std::cout << *pInt << std::endl;

	// The problem with unique_ptr is that it doesn support assignent, so 
	/*
		lets say we have this class
		class Contact  
		{
		private:
			static const int NAME_SIZE = 12;
			unique_ptr<const char[]> pName;
			int num;
		
		public:
			Contact() :pName(new char[NAME_SIZE]) 
			{                                                                      // works
				this->num = 0;
			}
			Contact(const char* name, int num) :pName(new char[NAME_SIZE]) 
			{
				this->pName = name;                                                                                   // not allowed	
				this->num = num;	
			}
		};


		You can use a unique_ptr as a member variable. The problem is that it doesn't support assignment, so this is illegal:

		Contact(const char* name, int num) :pName(new char[NAME_SIZE]) {
        	this->pName = name;                                                      // Assignment to pName
			this->num = num;	
		}
		
		The only way you can set the value of a unique_ptr is when you initialize it, and this has to be done in the initializer list:

		Contact(const char* name, int num) :pName(name) {                               // Initializes pName
    		this->num = num;	
		}
	 */
	
	/* DOESNT WORK
		const char* pName = "XYZ";
		unique_ptr<const char[]> ptr;
		ptr = pName;
		
		unique_ptr<int[]> pArray(new int[3]);
		int array[] = { 1, 2, 3 };
		pArray = array;
	
	*/

	/* WORK
		const char* pName = "XYZ";
		unique_ptr<const char[]> ptr(pName);
		
		unique_ptr<int[]> pArray(new int[]{1,2,3});	
	*/
	

	return 0;
}