#include <iter.hpp>

void leaks(void)
{
	system("leaks ex01");
}

int main(void)
{
	atexit(leaks);

	int array[5] = {0,1,2,3,4};
	iter<int, void (*)(int)>(array, 5, printElement);
	std::cout << std::endl;
	iter<int, void (*)(int&)>(array, 5, doubleElement);
	iter<int, void (*)(int)>(array, 5, printElement);
	std::cout << std::endl;
	std::string arrayS[5] = {"A", "B", "C", "D", "E"};
	iter<std::string, void (*)(std::string)>(arrayS, 5, printElement);
	std::cout << std::endl;
	iter<std::string, void (*)(std::string&)>(arrayS, 5, doubleElement);
	iter<std::string, void (*)(std::string)>(arrayS, 5, printElement);
	std::cout << std::endl;
}
