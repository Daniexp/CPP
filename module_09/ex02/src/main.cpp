#include <PmergeMe.hpp>
#include <PmergeMe.hpp>

/*
void leaks(void)
{
	system("leaks ex02");
}
*/
int main(int argc, char* argv[])
{
//	atexit(leaks);
	if (argc <= 1)
		return (-1); 
	PmergeMe containers; 
	try
	{
		containers = PmergeMe(argv + 1);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (-1);
	}
	std::cout << containers;
}
