#include <PmergeMe.hpp>

PmergeMe::PmergeMe()
{
//Const
}

PmergeMe::PmergeMe(const PmergeMe& src)
{
//Copy Const
	*this = src;
}

PmergeMe::~PmergeMe()
{
//Dest
}

PmergeMe::PmergeMe(char* argv[])
{
	if (!argv)
		return ;
	int number;
	try
	{
		for (int i = 0; argv[i]; i++)
		{
			//parse Char to Unsigned Int
			number = std::stoi(argv[i]);
			if (number < 0)
				throw std::logic_error(std::string("negative integer ") + argv[i]);
				//save Int in both containers
			this->firstContainer.insert(firstContainer.end(), number);
			this->secondContainer.push_back(number);
		}
	}
	catch (std::exception& e)
	{
		throw std::logic_error(std::string("Error: invalid positive integer sequence by ") + e.what());
	}
}

PmergeMe& PmergeMe::operator = (const PmergeMe& src)
{
	if (this != &src)
	{
		this->firstContainer = src.firstContainer;
		this->secondContainer = src.secondContainer;
	}
	return *this;
}

const std::vector<unsigned int> PmergeMe::getFirstContainer(void) const
{
	return this->firstContainer;
}

const std::list<unsigned int> PmergeMe::getSecondContainer(void) const
{
	return this->secondContainer;
}
void PmergeMe::shortFirstContainer()
{
	//Ordenar por parejas
	int size = firstContainer.size();
	for (int i = 0; size > 1 + i; i += 2)
	{
		if (firstContainer[i] > firstContainer[i + 1])
			std::swap(firstContainer[i], firstContainer[i + 1]);
	}
	//Recursively short the n/2 larger elements from each pair, creating a sorted sequence of n/2
	// of the input elements, in ascending order.
	shortLargerElements(firstContainer, 0, firstContainer.size() - 1);
	std::vector<unsigned int> shortedContainer;
	shortedContainer.push_back(firstContainer[0]);
	firstContainer.erase(firstContainer.begin());
	for (std::size_t i = 1; firstContainer.size() > i + 1; i++)
	{
		shortedContainer.push_back(firstContainer[i]);
		firstContainer.erase(firstContainer.begin() + i);
	}
	//Insert first pair of S
	shortedContainer.insert(shortedContainer.begin(), firstContainer[0]);
	firstContainer.erase(firstContainer.begin());
	
	//firstContainer = shortedContainer;
	std::cout << "S: " << "{";
	for (std::size_t i = 0; i < shortedContainer.size(); i++)
	{
		std::cout << " " << shortedContainer[i] << " ";
	}
	std::cout << "}" << std::endl;
}

void PmergeMe::shortLargerElements(std::vector<unsigned int>& src, int start, int end)
{
	if (end - start > 0)
		return ;
	if (start < end)
	{
		for (int i = start; end > i + 2; i += 2)
		{
			if (src[i] > src[i + 2])
			{
				std::swap(src[i], src[i + 2]);
				std::swap(src[i + 1], src[i + 3]);
			}
		}
	}
    int mid = (start + end) / 2;
            shortLargerElements(src, start, mid);
            shortLargerElements(src, mid + 1, end);
}
/*
void PmergeMe::binarySearch(std::vector<unsigned int>& src, int start, int end)
{
}
*/
/*
void PmergeMe::shortSecondContainer(std::list<unsigned int>& src)
{
}

std::ostream& operator << (std::osteram& os, const PmergeMe& src)
{
}
*/

std::ostream& operator << (std::ostream& os, const PmergeMe& src)
{
	std::vector<unsigned int> vct = src.getFirstContainer();
	os << "{";
	for (std::size_t i = 0; i < vct.size(); i++)
	{
		os << " " << vct[i] << " ";
	}
	os << "}" << std::endl;

	return os;
}
