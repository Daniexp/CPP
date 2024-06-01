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

PmergeMe::PmergeMe(vector& src): firstContainer(src)
{
//Copy Const
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

const vector PmergeMe::getFirstContainer(void) const
{
	return this->firstContainer;
}

const list PmergeMe::getSecondContainer(void) const
{
	return this->secondContainer;
}
void printShortFirst(vector& src, vector& shorted, std::vector<int>& pairs)
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

void PmergeMe::shortPairs(vector& src)
{
	int middle = (src.size() / 2);
	for (int i = 0; i < middle; i++)
	{
		if (src[i] < src[i + middle])
			swap(src[i], src[i + middle]);
	}
}

void PmergeMe::shortPairs(list& src)
{
	    int middle = src.size() / 2;

	    list::iterator it1 = src.begin();
	    list::iterator it2 = src.begin();
	    std::advance(it2, middle);
	
	    for (int i = 0; i < middle; i++) {
	        list::iterator next_it1 = it1;
	        list::iterator next_it2 = it2;
		++next_it1;
		++next_it2;

	        if (*it1 < *it2) {
	            std::iter_swap(it1, it2);
	        }
	
	        it1 = next_it1;
	        it2 = next_it2;
	    }
}

void PmergeMe::splitPairs(vector& src, vector& shorted)
{
	int middle = (src.size() / 2);
	shorted.insert(shorted.begin(), src.begin(), src.begin() + (src.size() / 2));
	src.erase(src.begin(), src.begin() + middle);
}

void PmergeMe::splitPairs(list& src, list& shorted)
{
	int middle = (src.size() / 2);
	list::iterator firstPair = src.begin();
	for (int i = 0; i < middle; i++)
		++firstPair;
	shorted.insert(shorted.begin(), src.begin(), firstPair);
	src.erase(src.begin(), firstPair);
}

void PmergeMe::orderBiggestPairs(vector& shorted, vector& src)
{
	int size = (int) shorted.size();
	for (int i = 0; i < size - 1; i++)
		for (int j = 0; j < size - i - 1; j++)
			if (shorted[j] > shorted[j + 1])
			{
				swap(shorted[j], shorted[j + 1]);
				swap(src[j], src[j + 1]);
			}
}

void PmergeMe::orderBiggestPairs(list& shorted, list& src)
{
	int  size = (int) shorted.size();
	for (int i = 0; i < size - 1; i++)
		for (int j = 0; j < size - i - 1; j++)
		{
			list::iterator it = getIterator(shorted, j);
			list::iterator it2 = getIterator(shorted, j + 1);
			if ( *it > *it2)
			{
				list::iterator pair = getIterator(src, j);
				list::iterator pair2 = getIterator(src, j + 1);
				swap(*it, *it2);
				swap(*pair, *pair2);
			}
		}
}

std::vector<int> PmergeMe::savePairsOfUnshorted(vector& src, vector& shorted)
{
	std::vector<int> pairs;
	for (std::size_t i = 1; i < shorted.size(); i++)
		pairs.insert(pairs.end(), shorted[i]);
	std::size_t S = shorted.size();
	bool odd = S + S != S + src.size();
	if (odd)
		pairs.insert(pairs.end(), INT_MIN);
	shorted.insert(shorted.begin(), *src.begin());
	src.erase(src.begin());
	return pairs;
}

std::list<int> PmergeMe::savePairsOfUnshorted(list& src, list& shorted)
{
	std::list<int> pairs;
	for (std::size_t i = 1; i < shorted.size(); i++)
		pairs.insert(pairs.end(), *getIterator(shorted, i));
	std::size_t S = shorted.size();
	bool odd = S + S != S + src.size();
	if (odd)
		pairs.insert(pairs.end(), INT_MIN);
	shorted.insert(shorted.begin(), *src.begin());
	src.erase(src.begin());
	return pairs;
}
void	PmergeMe::reverseUnshortedPairsInGroupsOfPowerTwo(vector& src, std::vector<int>& pairs)
{
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
}

void PmergeMe::reverseUnshortedPairsInGroupsOfPowerTwo(list& src, std::list<int>& pairs)
{
	int saved= 2;
	int notReverse = src.size();
	int nextPowIndex = 3;
	int groupSize = 2;
	int prevGroupSize = 2;
	int firstUnshortedIndex = 0;
	int unshortedIndexPairs = 2;
	if (notReverse < 2)
		return ;
	std::swap(*pairs.begin(), *getIterator(pairs, 1));
	swap(*src.begin(), *getIterator(src, 1));
	while (saved < notReverse)
	{
		int first, last;
		first = firstUnshortedIndex + prevGroupSize;
		last = first + groupSize;
		if ((std::size_t) last > src.size())
			last = src.size() - 1;
		while (first < last)
		{
			swap(*getIterator(src,first), *getIterator(src, last));
			std::swap(*getIterator(pairs, unshortedIndexPairs), *getIterator(pairs, (unshortedIndexPairs + last - first)));
			unshortedIndexPairs++;
			first++;
			last--;
		}
		prevGroupSize = groupSize;
		saved += groupSize;
		groupSize = pow(2, nextPowIndex) - groupSize;
	}
}

void PmergeMe::insertPowerTwoGroupsByBinarySearchInSubsequences(vector& src, vector& shorted, std::vector<int>& pairs)
{
	while (!pairs.empty() && !src.empty())
	{
		if (pairs[0] == INT_MIN)
			binarySearchInsertion(shorted, src[0], 0, src.size() - 1);
		else
			binarySearchInsertion(shorted, src[0], 0,
					std::find(shorted.begin(), shorted.end(), pairs[0]) - shorted.begin() - 1);
		pairs.erase(pairs.begin());
		src.erase(src.begin());
	}
}

void PmergeMe::insertPowerTwoGroupsByBinarySearchInSubsequences(list& src, list& shorted, std::list<int>& pairs)
{
	while (!pairs.empty() && !src.empty())
	{
		if (*pairs.begin() == INT_MIN)
			binarySearchInsertion(shorted, *src.begin(), 0, src.size() - 1);
		else
		{
			list::iterator end = getIterator(shorted, *pairs.begin());
			binarySearchInsertion(shorted, *src.begin(), 0, getIndex(shorted, end));
		}
		pairs.erase(pairs.begin());
		src.erase(src.begin());
	}
}

void PmergeMe::shortFirstContainer(void)
{
	vector& src = this->firstContainer;
	vector shorted;
	std::vector<int> pairs;

	shortPairs(src);

	splitPairs(src, shorted);

	orderBiggestPairs(shorted, src);

	pairs = savePairsOfUnshorted(src, shorted);

	reverseUnshortedPairsInGroupsOfPowerTwo(src, pairs);

	insertPowerTwoGroupsByBinarySearchInSubsequences(src, shorted, pairs);

	this->firstContainer = shorted;
}

void PmergeMe::shortSecondContainer(void)
{
	list& src = this->secondContainer;
	list shorted;
	std::list<int> pairs;

	shortPairs(src);

	splitPairs(src, shorted);

	orderBiggestPairs(shorted, src);

	pairs = savePairsOfUnshorted(src, shorted);

	reverseUnshortedPairsInGroupsOfPowerTwo(src, pairs);

	insertPowerTwoGroupsByBinarySearchInSubsequences(src, shorted, pairs);

	this->secondContainer = shorted;
}

void PmergeMe::binarySearchInsertion(vector& S, const unsigned int srcValue, int start, int end)
{
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
		binarySearchInsertion(S, srcValue, start, middle); 
	else
		binarySearchInsertion(S, srcValue, middle, end); 
}
void PmergeMe::binarySearchInsertion(list& S, const unsigned int srcValue, int start, int end)
{
	if (end - start <= 0)
		return ;
	if (end - start == 1)
	{
		if (srcValue <= *getIterator(S, start))
			S.insert(getIterator(S, start), srcValue);
		else if (srcValue >= *getIterator(S, end))
			S.insert(getIterator(S, end + 1), srcValue);
		else
			S.insert(getIterator(S, end), srcValue);
		return ;
	}
	int middle = (end + start) / 2;
	if (*getIterator(S, middle) >= srcValue)
		binarySearchInsertion(S, srcValue, start, middle); 
	else
		binarySearchInsertion(S, srcValue, middle, end); 
}
void PmergeMe::swap(unsigned int& nmb1, unsigned int& nmb2)
{
	unsigned int tmp;
	tmp = nmb1;
	nmb1 = nmb2;
	nmb2 = tmp;
}

std::ostream& operator << (std::ostream& os, const PmergeMe& src)
{
	vector vct = src.getFirstContainer();
	os << "{";
	for (std::size_t i = 0; i < vct.size(); i++)
	{
		os << " " << vct[i] << " ";
	}
	os << "}" << std::endl;
	list lst = src.getSecondContainer();
	os << "{";
	for (list::iterator it = lst.begin(); it != lst.end(); it++)
	{
		os << " " << *it << " ";
	}
	os << "}" << std::endl;

	return os;
}

list::iterator PmergeMe::getIterator(list& src, int index)
{
	int size = src.size();
	if (size == 0 || index < 0)
		return src.end();
	list::iterator it;
	int middle = src.size() / 2;
	if (index <= middle)
	{
		it = src.begin();
		for (int it = 0; it < index; it++)
				++it;
	}
	else
	{
		it = src.end();
		for (int it = size; it > index; --it)
			--it;
	}
	return it;
}

std::list<int>::iterator PmergeMe::getIterator(std::list<int>& src, int index)
{
	int size = src.size();
	if (size == 0 || index < 0)
		return src.end();
	std::list<int>::iterator it;
	int middle = src.size() / 2;
	if (index <= middle)
	{
		it = src.begin();
		for (int it = 0; it < index; it++)
				++it;
	}
	else
	{
		it = src.end();
		for (int it = size; it > index; --it)
			--it;
	}
	return it;
}

int	PmergeMe::getIndex(list& src, list::iterator it)
{
	int i = 0;
	while (getIterator(src, i) != it)
		i++;
	return i;
}
