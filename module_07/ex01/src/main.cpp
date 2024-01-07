#include <iter.hpp>
int main(void)
{
	std::cout << "The proyect was created sucessfully." << std::endl;
	int array[5] = {0,1,2,3,4};
	iter(array, 5, printElement);
	std::cout << std::endl;
	iter(array, 5, doubleElement);
	iter(array, 5, printElement);
	std::cout << std::endl;
	std::string arrayS[5] = {"A", "B", "C", "D", "E"};
	iter(arrayS, 5, printElement);
	std::cout << std::endl;
	iter(arrayS, 5, doubleElement);
	iter(arrayS, 5, printElement);
	std::cout << std::endl;
}
