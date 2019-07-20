#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// behind scenes a vector of size has an array representation with a capacity that gets exchanged as vector grows or shrinks


	vector<double> Numbers(20,1.1);

	std::cout<< " Size: " <<Numbers.size() << std::endl;

	int Capacity = Numbers.capacity();

	std::cout<< " Capacity: " << Capacity << std::endl;

	for (int i= 0; i < 10000; i++)
	{
		Numbers.push_back(i);

		if (Capacity != Numbers.capacity())
		{
			//Numbers.shrink_to_fit(); Adjust capacity to exact size value
			Capacity = Numbers.capacity();
			std::cout << " At index : " << i << " Capacity changed to : " << Capacity << std::endl;;
		}
	}

	std::cout<< " --- Reduce vector ---- ";

	for (int i= 0; i < 10000; i++)
	{
		Numbers.pop_back();

		//Numbers.shrink_to_fit();

		if (Capacity != Numbers.capacity())
		{
			Capacity = Numbers.capacity();
			std::cout << " At index : " << i << " Capacity changed to : " << Capacity << std::endl;;
		}
	}


}