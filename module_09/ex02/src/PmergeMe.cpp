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
	for (int i = 0; size / 2  > 1 + i; i += 2)
	{
	}
	std::cout << "Vct after split an order pairs: " << "{";
	for (std::size_t i = 0; i < firstContainer.size(); i++)
	{
		std::cout << " " << firstContainer[i] << " ";
	}
	std::cout << "}" << std::endl;
	//Recursively short the n/2 larger elements from each pair, creating a sorted sequence of n/2
	// of the input elements, in ascending order.
	shortLargerElements(firstContainer, 0, firstContainer.size() - 1 - (firstContainer.size() % 2));

/*
	std::cout << "Vct after short pairs: " << "{";
	for (std::size_t i = 0; i < firstContainer.size(); i++)
	{
		std::cout << " " << firstContainer[i] << " ";
	}
	std::cout << "}" << std::endl;

	std::vector<unsigned int> shortedContainer;
	shortedContainer.push_back(firstContainer[0]);
	firstContainer.erase(firstContainer.begin());
	for (std::size_t i = 1; firstContainer.size() > i + 1; i++)
	{
		shortedContainer.push_back(firstContainer[i]);
		firstContainer.erase(firstContainer.begin() + i);
	}
	//Insert first pair of S
//	shortedContainer.insert(shortedContainer.begin(), firstContainer[0]);
//	firstContainer.erase(firstContainer.begin());
	while (firstContainer.empty() == false)
	{
		binarySearchInsertionVector(shortedContainer, firstContainer[0], 0, shortedContainer.size() - 1);
		//shortedContainer.erase(shortedContainer.begin());
		firstContainer.erase(firstContainer.begin());
	}
	firstContainer = shortedContainer;
	
	//firstContainer = shortedContainer;
*/
}

void PmergeMe::shortLargerElements(std::vector<unsigned int>& src, int start, int end)
{
	if (end - start <= 0)
		return ;
	int size = (int) src.size();
	if (start < end)
	{
		for (int i = start; end >= i; i += 2)
		{
			if (size > i + 3 && src[i] > src[i + 2])
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
void PmergeMe::binarySearchInsertionVector(std::vector<unsigned int>& src, const unsigned int value, int start, int end)
{
	std::cout << "Value: " << value << " start: " << start << " end: " << end << std::endl;
	std::cout << "vector: ";
	for (std::size_t i = 0; i<src.size() ; i++)
	{
		std::cout << " "  << src[i] << " ";
	}
	std::cout << std::endl;
//	if (0 < end - start)
//		return ;
//	if (src[end] == src[start] && end - start <= 0)
//		return ;
	if (1 == end - start)
	{
		if (value >= src[end])
			src.insert(src.begin() + end + 1, value);
		else if (value > src[start] && value < src[end])
			src.insert(src.begin() + end, value);
		else if (value <= src[start])
			src.insert(src.begin() + start, value);
		return;
	}
	int middle = (start + end) / 2;
	if ((unsigned int) middle < value)
	{
		binarySearchInsertionVector(src, value, middle, end);
//		binarySearchInsertionVector(src, value, start, middle);
	}
	else
		binarySearchInsertionVector(src, value, start, middle);
}
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
