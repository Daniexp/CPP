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
	PmergeMe containers(argv);
}
