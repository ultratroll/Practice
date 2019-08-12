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
		std::cout << "Hello im a test" << std::endl;
	}

};

int main()
{
	// The difference with shared pointers is that the memory pointed is not deleted until ALL pointers pointing to it are out of scope
	// And cant be used with arrays, online instances of objects

	
	shared_ptr<Test> pTest1(nullptr);
	{
		shared_ptr<Test> pTest2 = make_shared<Test>(); // This version with make_shared is supossed to be more efficient than -- shared_ptr<Test> pTest1(new Test());

		pTest1 = pTest2;

		auto pTest3 = pTest1;
	} 
	// Nothing is destroyed before finished, because pTest2 and pTest3 can leave scope but pTest1 still points to the same space in memory
	// We only see destroyed before finished if we move pTest1 inside the scope, thus, the case where shared_ptr actually cleans its memory, when all pointers leave scope


	std::cout << "Finished" << std::endl;

	return 0;
}