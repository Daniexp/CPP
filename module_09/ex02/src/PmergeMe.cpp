#include <PmergeMe.hpp>

PmergeMe::PmergeMe()
{
//Const
	timerFirst = 0;
	timerSecond = 0;
	timerFirstContainer = 0.0;
	timerSecondContainer = 0.0;
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
	clock_t startTime;
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
			startTime = clock();
			this->firstContainer.insert(firstContainer.end(), number);
			this->timerFirstContainer += static_cast<double>(clock() - startTime) / CLOCKS_PER_SEC;
			timerFirst += (clock() - startTime);
			startTime = clock();
			this->secondContainer.push_back(number);
			this->timerSecondContainer += static_cast<double>(clock() - startTime) / CLOCKS_PER_SEC;
			timerSecond += (clock() - startTime);
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
		this->timerFirstContainer = src.timerFirstContainer;
		this->timerSecondContainer = src.timerSecondContainer;
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

double PmergeMe::getTimerFirstContainer() const
{
	return this->timerFirstContainer;
}

double PmergeMe::getTimerSecondContainer() const
{
	return this->timerSecondContainer;
}

long int PmergeMe::getTimerFirst() const
{
	return this->timerFirst;
}

long int PmergeMe::getTimerSecond() const
{
	return this->timerSecond;
}

void printShort(vector& src, vector& shorted, std::vector<int>& pairs)
{
	std::cout << "Vector print" << std::endl;
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
void printShort(list& src, list& shorted, std::list<int>& pairs)
{
	std::cout << "List print" << std::endl;
	std::cout << "src: " << "{";
	for (list::iterator it = src.begin(); it != src.end(); it++)
		std::cout << " " << *it;
	std::cout << "}" << std::endl;
	std::cout << "-------------------" << std::endl;
	std::cout << "S: " << "{";
	for (list::iterator it = shorted.begin(); it != shorted.end(); it++)
		std::cout << " " << *it;
	std::cout << "}" << std::endl;
	std::cout << "-------------------" << std::endl;
	std::cout << "Pairs: " << "{";
	for (std::list<int>::iterator it = pairs.begin(); it != pairs.end(); it++)
		std::cout << " " << *it;
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
	        if (*it1 < *it2) {
	            std::iter_swap(it1, it2);
	        }
	        ++it1;
	        ++it2;
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
		pairs.insert(pairs.end(), -1);
	shorted.insert(shorted.begin(), *src.begin());
	src.erase(src.begin());
	return pairs;
}

std::list<int> PmergeMe::savePairsOfUnshorted(list& src, list& shorted)
{
	std::list<int> pairs;
	for (std::size_t i = 1; i < shorted.size(); ++i)
		pairs.insert(pairs.end(), *getIterator(shorted, i));
	std::size_t S = shorted.size();
	bool odd = S + S != S + src.size();
	if (odd)
		pairs.insert(pairs.end(), -1);
	shorted.insert(shorted.begin(), *src.begin());
	src.erase(src.begin());
	return pairs;
}
void	PmergeMe::reverseUnshortedPairsInGroupsOfPowerTwo(vector& src, std::vector<int>& pairs)
{
	int saved = 2;
	int notReverse = src.size();
	int nextPowIndex = 3;
	int groupSize = 2;
	int unshortedIndexPairs = 2;
	if (notReverse < 2)
		return ;
	std::swap(pairs[0], pairs[1]);
	swap(src[0], src[1]);
	while (saved < notReverse)
	{
		int first, last;
		first = unshortedIndexPairs;
		last = first + groupSize - 1;
		if ((std::size_t) last >= src.size())
			last = src.size() - 1;
		while (first < last)
		{
			swap(src[first], src[last]);
			std::swap(pairs[first], pairs[last]);
			first++;
			last--;
		}
		unshortedIndexPairs += groupSize - 1;
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
	int unshortedIndexPairs = 2;
	if (notReverse < 2)
		return ;
	std::iter_swap(pairs.begin(), getIterator(pairs, 1));
	std::iter_swap(src.begin(), getIterator(src, 1));
	while (saved < notReverse)
	{
		int first, last;
		first = unshortedIndexPairs;
		last = first + groupSize - 1;
		if ((std::size_t) last >= src.size())
			last = src.size() - 1;
		while (first < last)
		{
			std::iter_swap(getIterator(src, first), getIterator(src, last));
			std::iter_swap(getIterator(pairs, first), getIterator(pairs, last));
			first++;
			last--;
		}
		unshortedIndexPairs += groupSize - 1;
		saved += groupSize;
		groupSize = pow(2, nextPowIndex) - groupSize;
	}
}

void PmergeMe::insertPowerTwoGroupsByBinarySearchInSubsequences(vector& src, vector& shorted, std::vector<int>& pairs)
{
	while (!pairs.empty() && !src.empty())
	{
		if (pairs[0] < 0)
			binarySearchInsertion(shorted, src[0], 0, shorted.size() - 1);
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
		if (*pairs.begin() < 0)
			binarySearchInsertion(shorted, *src.begin(), 0, shorted.size() - 1);
		else
		{
			std::size_t end = 0;
			while (end < shorted.size() && *getIterator(shorted, end) != (unsigned int) *pairs.begin())
				end++;
			if (end < shorted.size())
				binarySearchInsertion(shorted, *src.begin(), 0, end);
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

void	PmergeMe::shortContainersWithTimers()
{
	clock_t startTime = clock();
	shortFirstContainer();
	this->timerFirstContainer += static_cast<double>(clock() - startTime) / CLOCKS_PER_SEC;
	this->timerFirst += clock() - startTime;
	startTime = clock();
	shortSecondContainer();
	this->timerSecondContainer += static_cast<double>(clock() - startTime) / CLOCKS_PER_SEC;
	this->timerSecond += (clock() - startTime);
}

void PmergeMe::binarySearchInsertion(vector& S, const unsigned int srcValue, int start, int end)
{
	if (start > end)
	{
		S.insert(S.begin() + start, srcValue);
		return;
	}
	if (end - start <= 0)
	{
		if (srcValue <= S[start])
			S.insert(S.begin() + start, srcValue);
		else
			S.insert(S.begin() + start + 1, srcValue);
		return;
	}
	int middle = (start + end) / 2;
	if (S[middle] > srcValue)
		binarySearchInsertion(S, srcValue, start, middle - 1);
	else
		binarySearchInsertion(S, srcValue, middle + 1, end);
/*
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
	if (S[middle] > srcValue)
		binarySearchInsertion(S, srcValue, start, middle); 
	else
		binarySearchInsertion(S, srcValue, middle, end); 
*/
}

std::list<unsigned int>::iterator advance(std::list<unsigned int>::iterator it, int n) {
    while (n-- > 0) ++it;
    return it;
}

void PmergeMe::binarySearchInsertion(list& S, const unsigned int srcValue, int start, int end)
{
/*
   if (start > end) {
        std::list<unsigned int>::iterator it = advance(S.begin(), start);
        S.insert(it, srcValue);
        return;
    }
    if (end - start <= 0) {
        std::list<unsigned int>::iterator it = advance(S.begin(), start);
        if (srcValue <= *it)
            S.insert(it, srcValue);
        else
            S.insert(++it, srcValue);
        return;
    }
    int middle = (start + end) / 2;
    std::list<unsigned int>::iterator it = advance(S.begin(), middle);
    if (*it > srcValue)
        binarySearchInsertion(S, srcValue, start, middle - 1);
    else
        binarySearchInsertion(S, srcValue, middle + 1, end);
*/
	if (start > end)
	{
		S.insert(getIterator(S, start), srcValue);
		return;
	}
	if (end - start <= 0)
	{
		if (srcValue <= *getIterator(S, start))
			S.insert(getIterator(S, start), srcValue);
		else
			S.insert(getIterator(S, start + 1), srcValue);
		return;
	}
	int middle = (start + end) / 2;
	if (*getIterator(S, middle) > srcValue)
		binarySearchInsertion(S, srcValue, start, middle - 1);
	else
		binarySearchInsertion(S, srcValue, middle + 1, end);
}
void PmergeMe::swap(unsigned int& nmb1, unsigned int& nmb2)
{
	unsigned int tmp;
	tmp = nmb1;
	nmb1 = nmb2;
	nmb2 = tmp;
}
void PmergeMe::swap(list::iterator it1, list::iterator it2)
{
	unsigned int tmp;
	tmp = *it1;
	*it1 = *it2;
	*it2 = tmp;
}
void PmergeMe::swap(std::list<int>::iterator it1, std::list<int>::iterator it2)
{
	unsigned int tmp;
	tmp = *it1;
	*it1 = *it2;
	*it2 = tmp;
}

std::ostream& operator << (std::ostream& os, const PmergeMe& src)
{
	vector vct = src.getFirstContainer();
	double time1 = src.getTimerFirstContainer();
	double time2 = src.getTimerSecondContainer();
	long int time3 = src.getTimerFirst();
	long int time4 = src.getTimerSecond();
	std::size_t size = vct.size();
	os << "Time to process a range of " << size << " elements with std::vector<unsigned int> : " << time1 << " s or " << time3 << " nmb of clocks" << std::endl;
	os << "Time to process a range of " << size << " elements with std::vector<unsigned int> : " << time2 << " s or " << time4 << " nmb of clocks" << std::endl;
	os << std::endl;
/*
	os << "After:";
	for (std::size_t i = 0; i < vct.size(); i++)
	{
		os << " " << vct[i];
	}
*/
/*
	list lst = src.getSecondContainer();
	os << "{";
	for (list::iterator it = lst.begin(); it != lst.end(); it++)
	{
		os << " " << *it << " ";
	}
	os << "}" << std::endl;
*/

	return os;
}

list::iterator PmergeMe::getIterator(list& src, unsigned int index)
{
	int size = src.size();
	if (size == 0 || index < 0)
		return src.end();
	list::iterator it = src.begin();
	std::advance(it, index);
	return it;
}

std::list<int>::iterator PmergeMe::getIterator(std::list<int>& src, int index)
{
	int size = src.size();
	if (size == 0 || index < 0 || index >= size)
		return src.end();
	std::list<int>::iterator it = src.begin();
	std::advance(it, index);
	return it;
}

int	PmergeMe::getIndex(list& src, list::iterator it)
{
	int i = 0;
	while (getIterator(src, i) != it)
		i++;
	return i;
}
