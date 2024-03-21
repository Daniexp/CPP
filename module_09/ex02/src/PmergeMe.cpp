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
	for (int i = 0; size > i; i++)
	{
		if (firstContainer[i] < firstContainer[i + size])
			swap(firstContainer[i], firstContainer[i + size]);
	}
	//Recursively short the Larger elements to make a shorted size sequence of S.
	shortLargerElements(firstContainer, 0, size - 1); 
	//Save pairs values of the unInsertedElements
	for (std::size_t i = 1; i < firstContainer.size() / 2; i++)
		pairs.insert(pairs.end(), firstContainer[i]);
	
	//Insert at the start of S the element that was paired with the first and smallest element of S.
	firstContainer.insert(firstContainer.begin(), firstContainer[size]);
	firstContainer.erase(firstContainer.begin() + size + 1);
	std::cout << "Antes firstContainer: " << "{";
	for (std::size_t i = 0; i < firstContainer.size(); i++)
		std::cout << " " << firstContainer[i] << " ";
	std::cout << "}" << std::endl;
	
	//Create groups and short group element in descending order
	//Group: the sums of sizes of every two adjacent groups form a sequence of powers of two
	splitUnshortedElements(firstContainer);
	
	std::cout << "desues firstContainer: " << "{";
	for (std::size_t i = 0; i < firstContainer.size(); i++)
		std::cout << " " << firstContainer[i] << " ";
	std::cout << "}" << std::endl;

	//Insert the remaining n / 2 - 1 , S elements into S once at a time, whith binary search in subsequences of S to determine the position at which element should be inserted. 
	while (!pairs.empty())
	{
		binarySearchInsertionVector(firstContainer, 
		std::find(firstContainer.begin(), firstContainer.end(), pairs[0]),
		firstContainer.begin(), //calcular final a partir de la longuitud de pairs
);
		pairs.erase(pairs.begin());
	}
/*
	int i = firstContainer.size() / 2 + (firstContainer.size() % 2) - 1;
	while (firstContainer.begin() + i != firstContainer.end())
	{
		int pair = 0;
		while (firstContainer[pair] != pairs[i])
			pair++;
		pairs.erase(pairs.begin());
	}
*/
}

void PmergeMe::shortLargerElements(std::vector<unsigned int>& src, int start, int end) {
	if (end - start <= 0)
		return ;
	int size = (int) firstContainer.size() / 2;
	if (start < end)
	{
		for (int i = end; start <= i - 1; i--)
		{
		//	std::cout << "i: " << src[i] << " i - 1: " << src[i - 1] << std::endl;
		//	std::cout << "i + size: " << src[i + size] << " i + size - 1: " << src[i + size - 1] << std::endl;
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
//	test group sizes
//	std::size_t length = 3000;
	std::size_t length = src.size() / 2 + (src.size() % 2) - 1;
	std::size_t saved = 2;
	int i = 3;
	int groupSize = 2;
	//invertir primer grupo
	if (length < 2)
		return;
	swap(src[src.size() / 2 + 1], src[src.size() / 2 + 2]);
	
	while (saved < length - (src.size() % 2))
	{
	//std::cout << "Group size: " << groupSize << " " << std::endl;
		int start, end;
		//Invertir números desde src[src.size() / 2 + saved] hasta +groupSize 
		start = src.size() / 2 + saved + 1;
		//end = (length + 1 < saved + groupSize) ? start + groupSize - 1 : src.size() - 1;
		
		end = start + groupSize / 2;
	//	std::cout << "Start: " << start << " , End: " << end << std::endl;
		while (start < end)
		{
			swap(src[start], src[end]);
			start++;
			end--;
		}
		saved += groupSize;
		groupSize = pow(2, i) - groupSize;
		i++;
	}
}

void PmergeMe::binarySearchInsertionVector(std::vector<unsigned int>& src, const unsigned int value, int start, int end)
{
	//Subsequence of S:	Is the sequence starting with pair of the element that is going to be insert to the end of S.
	if (end - start <= 0)
		return ;
	if (end - start == 1)
	{
		firstContainer.insert(src.begin() + end, src[value]);
		firstContainer.erase(src.begin() + value);
	}
	int middle = (end + start) / 2;
	if (src[middle] >= src[value])
		binarySearchInsertionVector(src, value, start, middle); 
	else
		binarySearchInsertionVector(src, value, middle, end); 
	
}
/*
void PmergeMe::shortSecondContainer(std::list<unsigned int>& src)
{
}

std::ostream& operator < (std::osteram& os, const PmergeMe& src)
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
