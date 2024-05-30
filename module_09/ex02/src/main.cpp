#include <PmergeMe.hpp>

/*
void leaks(void)

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
		containers.shortFirstContainer();
		//containers.shortFirstContainer(containers.getFirstContainer());
//		std::cout << containers;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (-1);
	}
	std::vector<unsigned int> result = containers.getFirstContainer();
	std::cout << containers;
}
