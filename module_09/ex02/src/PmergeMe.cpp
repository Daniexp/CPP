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
	//4
	//2 2 6 10 22
//	test group sizes
//	std::size_t length = 3000;
/*
	std::size_t length = (src.size() / 2) + (src.size() % 2) - 1;
	std::size_t saved = 2;
	int i = 3;
	int groupSize = 2;
	//invertir primer grupo
	if (length < 2)
		return;
	swap(src[src.size() / 2 + 1], src[src.size() / 2 + 2]);
	swap(pairs[0], pairs[1]);
	while (saved < length - (src.size() % 2))
	{
	//std::cout << "Group size: " << groupSize << " " << std::endl;
		int start, end;
		//Invertir números desde src[src.size() / 2 + saved] hasta +groupSize 
		start = src.size() / 2 + saved + 1;
		//end = (length + 1 < saved + groupSize) ? start + groupSize - 1 : src.size() - 1;
		end = start + groupSize / 2;
		std::cout << "Start: " << start << " , End: " << end << std::endl;
		while (start < end)
		{
			swap(src[start], src[end]);
			swap(pairs[start - src.size() / 2 - 1], pairs[end - src.size() / 2 - 1]);
			start++;
			end--;
		}
		saved += groupSize;
		groupSize = pow(2, i) - groupSize;
		i++;
	}
*/
	int saved= 2;
	int notReverse = src.size() / 2 - 1 + src.size() % 2;
	int nextPowIndex = 3;
	int groupSize = 2;
	int prevGroupSize = 2;
	int firstUnshortedIndex = src.size() / 2 + 1;
	int unshortedIndexPairs = 2;
/*
	std::size_t saved= 2;
	std::size_t notReverse = src.size() / 2 - 1 + src.size() % 2;
	std::size_t nextPowIndex = 3;
	std::size_t groupSize = 2;
	std::size_t prevGroupSize = 2;
	std::size_t firstUnshortedIndex = src.size() / 2 + 1;
	std::size_t unshortedIndexPairs = 2;
 */
	if (notReverse < 2)
		return ;
	swap(src[firstUnshortedIndex], src[firstUnshortedIndex + 1]);
	swap(pairs[0], pairs[1]);
	std::cout << firstUnshortedIndex << " " << firstUnshortedIndex + 1 << std::endl;
	while (saved < notReverse)
	{
		int first, last;
		first = firstUnshortedIndex + prevGroupSize;
//		last = first + groupSize - 1;
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
