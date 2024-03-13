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
	int size = firstContainer.size() / 2;
	std::vector<unsigned int> pairs;
//	unsigned int tmp;
	for (int i = 0; size > i; i++)
	{
		std::cout << "i: " << firstContainer[i] << " i + size: " << firstContainer[i + size] << std::endl;
		if (firstContainer[i] < firstContainer[i + size])
			swap(firstContainer[i], firstContainer[i + size]);
		//añadir iterador al vector de parejas
	}
	std::cout << "split an order pairs: " << "{";
	for (std::size_t i = 0; i < firstContainer.size(); i++)
		std::cout << " " << firstContainer[i] << " ";
	std::cout << "}" << std::endl;
	//Recursively short the Larger elements to make a shorted size sequence of S.
	shortLargerElements(firstContainer, 0, size - 1); 
	//Save pairs values of the unInsertedElements
	for (int i = firstContainer.size() - 1 - firstContainer.size() % 2; i > size; i--)
		pairs.insert(pairs.begin(), firstContainer[i - size]);
//	pairs = savePairsOfUnshortedElements();
	std::cout << "pairs of the unshorted elements (not in order): " << "{";
	for (std::size_t i = 0; i < pairs.size(); i++)
		std::cout << " " << pairs[i] << " ";
	std::cout << "}" << std::endl;
	
	//Insert at the start of S the element that was paired with the first and smallest element of S.
	firstContainer.insert(firstContainer.begin(), firstContainer[size]);
	firstContainer.erase(firstContainer.begin() + size + 1);
	
	//Create groups and short group element in descending order
	splitUnshortedElements(firstContainer);
	//Group: the sums of sizes of every two adjacent groups form a sequence of powers of two

	//Insert the remaining n / 2 - 1 , S elements into S once at a time, whith binary search in subsequences of S to determine the position at which element should be inserted. 
}

void PmergeMe::shortLargerElements(std::vector<unsigned int>& src, int start, int end) {
	if (end - start <= 0)
		return ;
	int size = (int) firstContainer.size() / 2;
	if (start < end)
	{
		for (int i = end; start <= i - 1; i--)
		{
			std::cout << "i: " << src[i] << " i - 1: " << src[i - 1] << std::endl;
			std::cout << "i + size: " << src[i + size] << " i + size - 1: " << src[i + size - 1] << std::endl;
			if (src[i] < src[i - 1])
			{
				swap(src[i], src[i - 1]);
				swap(src[i + size], src[i + size - 1]);
			}
		}
	}
    int mid = (start + end) / 2;
            shortLargerElements(src, start, mid);
            shortLargerElements(src, mid + 1, end);
}

void PmergeMe::splitUnshortedElements(std::vector<unsigned int>& src)
{
	//4
	//2 2 6 10 22
	std::size_t length = src.size() / 2 + (src.size() % 2);
	std::size_t saved = 2;
	int i = 2;
	int groupSize = 2;
	//invertir primer grupo
	if (length < 2 - (src.size() % 2))
		return;
	swap(src[length], src[length + 1]);
	
	std::cout << "Group size: ";
	while (saved < length)
	{
		std::cout << groupSize << " ";
		//Invertir números desde src[saved] hasta  + length	
		saved += groupSize;
		groupSize = pow(2, i - 1) - groupSize;
		i++;
	}
	std::cout << std::endl;
}

void PmergeMe::binarySearchInsertionVector(std::vector<unsigned int>& src, const unsigned int value, int start, int end)
{
	//Subsequence of S:	Is the sequence starting with pair of the element that is going to be insert to the end of S.
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
void PmergeMe::swap(unsigned int& nmb1, unsigned int& nmb2)
{
	unsigned int tmp;
	tmp = nmb1;
	nmb1 = nmb2;
	nmb2 = tmp;
}

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
