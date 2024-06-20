#include <PmergeMe.hpp>

/*
void leaks(void)

	system("leaks ex02");
}
*/
template <typename Container>
void isSorted(const Container& container) {
    if (container.empty()) return ;

    typename Container::const_iterator it = container.begin();
    typename Container::const_iterator next_it = it;
    ++next_it;

    while (next_it != container.end()) {
        if (*next_it < *it) {
		throw std::logic_error("The container is not correctly sorted");
        }
        ++it;
        ++next_it;
    }
}

int main(int argc, char* argv[])
{
//	atexit(leaks);
	if (argc <= 1)
		return (-1); 
	PmergeMe containers; 
	try
	{
		containers = PmergeMe(argv + 1);
//		containers.shortFirstContainer();
//		containers.shortSecondContainer();
		containers.shortContainersWithTimers();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (-1);
	}
	std::cout << containers;
	vector first = containers.getFirstContainer();
	list second = containers.getSecondContainer();
	isSorted(first);
	isSorted(second);
}
