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
			std::stringstream ss(argv[i]);
			ss >> number;
			if (ss.fail()) {
				throw std::logic_error(std::string("not a number") + argv[i]);
			}
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
void printShortFirst(std::vector<unsigned int>& src, std::vector<unsigned int>& shorted, std::vector<int>& pairs)
{
	std::cout << "src: " << "{";
	for (std::size_t i = 0; i < src.size(); i++)
		std::cout << " " << src[i];
	std::cout << "}" << std::endl;
	std::cout << "-------------------" << std::endl;
	std::cout << "S: " << "{";
	for (std::size_t i = 0; i < shorted.size(); i++)
		std::cout << " " << shorted[i];
	std::cout << "}" << std::endl;
	std::cout << "-------------------" << std::endl;
	std::cout << "Pairs: " << "{";
	for (std::size_t i = 0; i < pairs.size(); i++)
		std::cout << " " << pairs[i];
	std::cout << "}" << std::endl;
	std::cout << "-------------------" << std::endl;
}
void PmergeMe::shortPairs(std::vector<unsigned int>& src)
{
	int middle = (src.size() / 2);
	for (int i = 0; i < middle; i++)
	{
		if (src[i] < src[i + middle])
			swap(src[i], src[i + middle]);
	}
}

void PmergeMe::shortFirstContainer(std::vector<unsigned int> src)
{
	std::vector<unsigned int> shorted;
	std::vector<int> pairs;// = savePairs(shorted);
	int middle = (src.size() / 2);
	shortPairs(src);
	shorted.insert(shorted.begin(), src.begin(), src.begin() + (src.size() / 2));
	src.erase(src.begin(), src.begin() + middle);

	printShortFirst(src, shorted, pairs);
//Order by biggest pairs
	
	int size = (int) shorted.size();
	for (int i = 0; i < size - 1; i++)
		for (int j = 0; j < size - i - 1; j++)
			if (shorted[j] > shorted[j + 1])
			{
				swap(shorted[j], shorted[j + 1]);
				swap(src[j], src[j + 1]);
			}

//	printShortFirst(src, shorted, pairs);
	for (std::size_t i = 1; i < shorted.size(); i++)
		pairs.insert(pairs.end(), shorted[i]);
	std::size_t S = shorted.size();
	bool odd = S + S != S + src.size();
	if (odd)
		pairs.insert(pairs.end(), INT_MIN);
	shorted.insert(shorted.begin(), *src.begin());
	src.erase(src.begin());

//	printShortFirst(src, shorted, pairs);

	int saved= 2;
	int notReverse = src.size();
	int nextPowIndex = 3;
	int groupSize = 2;
	int prevGroupSize = 2;
	int firstUnshortedIndex = 0;
	int unshortedIndexPairs = 2;
	if (notReverse < 2)
		return ;
	std::swap(pairs[0], pairs[1]);
	swap(src[0], src[1]);
	while (saved < notReverse)
	{
		int first, last;
		first = firstUnshortedIndex + prevGroupSize;
		last = first + groupSize;
		if ((std::size_t) last > src.size())
			last = src.size() - 1;
		while (first < last)
		{
			swap(src[first], src[last]);
			std::swap(pairs[unshortedIndexPairs], pairs[unshortedIndexPairs + (last - first)]);
			unshortedIndexPairs++;
			first++;
			last--;
		}
		prevGroupSize = groupSize;
		saved += groupSize;
		groupSize = pow(2, nextPowIndex) - groupSize;
	}

//	printShortFirst(src, shorted, pairs);

	while (!pairs.empty() && !src.empty())
	{
		if (pairs[0] == INT_MIN)
			binarySearchInsertionVector(shorted, src[0], 0, src.size() - 1);
		else
			binarySearchInsertionVector(shorted, src[0], 0,
					std::find(shorted.begin(), shorted.end(), pairs[0]) - shorted.begin() - 1);
		pairs.erase(pairs.begin());
		src.erase(src.begin());
	}
//	printShortFirst(src, shorted, pairs);
}

void PmergeMe::binarySearchInsertionVector(std::vector<unsigned int>& S, const unsigned int srcValue, int start, int end)
{
	std::cout << "value to insert: " << srcValue << " start: " << start << " end: " << end << std::endl;
	if (end - start <= 0)
		return ;
	if (end - start == 1)
	{
		if (srcValue <= S[start])
			S.insert(S.begin() + start, srcValue);
		else if (srcValue >= S[end])
			S.insert(S.begin() + end + 1, srcValue);
		else
			S.insert(S.begin() + end, srcValue);
		return ;
	}
	int middle = (end + start) / 2;
	if (S[middle] >= srcValue)
		binarySearchInsertionVector(S, srcValue, start, middle); 
	else
		binarySearchInsertionVector(S, srcValue, middle, end); 
	
}

void PmergeMe::shortFirstContainer()
{
	//Ordenar por parejas
	int size = firstContainer.size() / 2;
	std::vector<unsigned int> pairs;
	for (int i = 0; size > i; i++)
	{
//		std::cout << "number: " << firstContainer[i] << " pair: " << firstContainer[i + size] << std::endl;
		if (firstContainer[i] < firstContainer[i + size])
			swap(firstContainer[i], firstContainer[i + size]);
	}
	//Save pairs values of the unInsertedElements
	for (std::size_t i = 0; i < firstContainer.size() / 2; i++)
		pairs.insert(pairs.end(), firstContainer[i]);
	//Recursively short the Larger elements to make a shorted size sequence of S.
//	shortLargerElements(firstContainer, 0, size - 1); 
	for (int i = 0; i < size - 1; i++)
		for (int j = 0; j < size - i - 1; j++)
			if (firstContainer[j] > firstContainer[j + 1])
			{
				swap(firstContainer[j], firstContainer[j + 1]);
				swap(pairs[j], pairs[j + 1]);
			}
/*
	std::cout << "despues de ordenar por parejas: " << "{";
	for (std::size_t i = 0; i < firstContainer.size(); i++)
		std::cout << " " << firstContainer[i] << " ";
	std::cout << "}" << std::endl;
*/	
	//Insert at the start of S the element that was paired with the first and smallest element of S.
	firstContainer.insert(firstContainer.begin(), firstContainer[size]);
	firstContainer.erase(firstContainer.begin() + size + 1);
	pairs.erase(pairs.begin());
/*
	std::cout << "Antes firstContainer: " << "{";
	for (std::size_t i = 0; i < firstContainer.size(); i++)
		std::cout << " " << firstContainer[i] << " ";
	std::cout << "}" << std::endl;
	std::cout << "Antes pairs: " << "{";
	for (std::size_t i = 0; i < pairs.size(); i++)
		std::cout << " " << pairs[i] << " ";
	std::cout << "}" << std::endl;
*/
	
	//Create groups and short group element in descending order
	//Group: the sums of sizes of every two adjacent groups form a sequence of powers of two
	size_t unPairElement = firstContainer[firstContainer.size() - 1];
	pairs.insert(pairs.end(), UINT_MAX);

	splitUnshortedElements(firstContainer, pairs);
	
/*
	std::cout << "desues firstContainer: " << "{";
	for (std::size_t i = 0; i < firstContainer.size(); i++)
		std::cout << " " << firstContainer[i] << " ";
	std::cout << "}" << std::endl;
	std::cout << "Despues pairs: " << "{";
	for (std::size_t i = 0; i < pairs.size(); i++)
		std::cout << " " << pairs[i] << " ";
	std::cout << "}" << std::endl;
*/
	

	//Insert the remaining n / 2 - 1 , S elements into S once at a time, whith binary search in subsequences of S to determine the position at which element should be inserted. 
	bool odd = (firstContainer.size() % 2) == 1;
	int cnt = (firstContainer.size() / 2);
	while (!pairs.empty())
	{
/*
		std::cout << "index to insert :" << cnt << std::endl;
		std::cout << "value to insert :" << firstContainer[cnt] << std::endl;
		std::cout << "index of the pair :" <<  std::find(firstContainer.begin(), firstContainer.end(), pairs[0]) - firstContainer.begin() << std::endl;
*/
		if (odd && firstContainer[cnt] == unPairElement && pairs[0] == UINT_MAX)
			binarySearchInsertionVector(firstContainer, cnt, 0, cnt - 1);
		else
		{
			binarySearchInsertionVector(firstContainer, cnt, 0,
				std::find(firstContainer.begin(), firstContainer.end(), pairs[0]) - firstContainer.begin() - 1);
		}
		pairs.erase(pairs.begin());
		cnt++;
/*
	std::cout << "AFter insert elemtn: " << "{";
	for (std::size_t i = 0; i < firstContainer.size(); i++)
		std::cout << " " << firstContainer[i] << " ";
	std::cout << "}" << std::endl;
	std::cout << "after insett elent pairs: " << "{";
	for (std::size_t i = 0; i < pairs.size(); i++)
		std::cout << " " << pairs[i] << " ";
	std::cout << "}" << std::endl;
	std::cout << std::endl;
*/
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
	//		std::cout << "i: " << src[i] << " i - 1: " << src[i - 1] << std::endl;
	//		std::cout << "i + size: " << src[i + size] << " i + size - 1: " << src[i + size - 1] << std::endl;
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
//Debugear segfault
void PmergeMe::splitUnshortedElements(std::vector<unsigned int>& src, std::vector<unsigned int>& pairs)
{
	int saved= 2;
	int notReverse = src.size() / 2 - 1 + src.size() % 2;
	int nextPowIndex = 3;
	int groupSize = 2;
	int prevGroupSize = 2;
	int firstUnshortedIndex = src.size() / 2 + 1;
	int unshortedIndexPairs = 2;
	if (notReverse < 2)
		return ;
	swap(src[firstUnshortedIndex], src[firstUnshortedIndex + 1]);
	swap(pairs[0], pairs[1]);
	std::cout << firstUnshortedIndex << " " << firstUnshortedIndex + 1 << std::endl;
	while (saved < notReverse)
	{
		int first, last;
		first = firstUnshortedIndex + prevGroupSize;
		last = first + groupSize;
		if ((std::size_t) last > src.size())
			last = src.size() - 1;
		std::cout << "-- --" << std::endl;
		while (first < last)
		{
			std::cout << "first: " << first << " last: " << last<< " unshortedIndexPairs: " << unshortedIndexPairs << " end unshorted: " << unshortedIndexPairs + (last - first) << " pairs lenght: " << pairs.size() << " last - first: " << last - first << std::endl;

			swap(src[first], src[last]);
			swap(pairs[unshortedIndexPairs], pairs[unshortedIndexPairs + (last - first)]);
			unshortedIndexPairs++;
			first++;
			last--;
		}

		prevGroupSize = groupSize;
		saved += groupSize;
		groupSize = pow(2, nextPowIndex) - groupSize;
	}
}

/*
void PmergeMe::binarySearchInsertionVector(std::vector<unsigned int>& src, const unsigned int value, int start, int end)
{
	//Subsequence of S:	Is the sequence starting with pair of the element that is going to be insert to the end of S.
	//std::cout << "start: " << start << " end: " << end << " src start: "<< src[start]<<" src end: " << src[end] << std::endl;
	if (end - start <= 0)
		return ;
	if (end - start == 1)
	{
//		std::cout << "pos to erase: " << value << " value: " << src[value] << std::endl;
//		std::cout << "pos to insert: " << end << " value: " << src[value] << std::endl;
		if (src[value] <= src[start])
			firstContainer.insert(src.begin() + start, src[value]);
		else if (src[value] >= src[end])
			firstContainer.insert(src.begin() + end + 1, src[value]);
		else
			firstContainer.insert(src.begin() + end, src[value]);
		firstContainer.erase(src.begin() + value + 1);
		return ;
	}
	int middle = (end + start) / 2;
	if (src[middle] >= src[value])
		binarySearchInsertionVector(src, value, start, middle); 
	else
		binarySearchInsertionVector(src, value, middle, end); 
	
}
*/
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
