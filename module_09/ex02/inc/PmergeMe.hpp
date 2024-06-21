#ifndef PMERGEME_H
#define PMERGEME_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <math.h>
#include <algorithm>
#include <limits.h>
#include <sstream>
typedef std::vector<unsigned int> vector;
typedef std::list<unsigned int> list;

class PmergeMe
{
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(char* argv[]);
	PmergeMe(vector& src);
	PmergeMe(const PmergeMe& src);
	PmergeMe& operator=(const PmergeMe& src);
	const vector getFirstContainer(void) const;
	const list getSecondContainer(void) const;
	double getTimerFirstContainer() const;
	double getTimerSecondContainer() const;
	long int getTimerFirst() const;
	long int getTimerSecond() const;

	void shortFirstContainer();
	void shortSecondContainer();
	void shortContainersWithTimers();

private:
	void saveIntegerSequence(char* argv[], void saveMethod(void));

	void binarySearchInsertion(vector& S, const unsigned int srcValue, int start, int end);
	void binarySearchInsertion(list& S, const unsigned int srcValue, int start, int end);

	void swap(unsigned int& nmb1, unsigned int& nmb2);
	void swap(list::iterator it1, list::iterator it2);
	void swap(std::list<int>::iterator it1, std::list<int>::iterator it2);

	vector		firstContainer;
	list		secondContainer;
	const	vector 	originalSequence;
	double		timerFirstContainer;
	double		timerSecondContainer;
	long int	timerFirst;
	long int	timerSecond;

	void shortPairs(vector& src);
	void splitPairs(vector& src, vector& shorted);
	void orderBiggestPairs(vector& shorted, vector& src);
	std::vector<int> savePairsOfUnshorted(vector& src, vector& shorted);
	void	reverseUnshortedPairsInGroupsOfPowerTwo(vector& src, std::vector<int>& pairs);
	void	insertPowerTwoGroupsByBinarySearchInSubsequences(vector& src, vector& shorted, std::vector<int>& pairs);

	void shortPairs(list& src);
	void splitPairs(list& src, list& shorted);
	void orderBiggestPairs(list& shorted, list& src);
	std::list<int> savePairsOfUnshorted(list& src, list& shorted);
	void	reverseUnshortedPairsInGroupsOfPowerTwo(list& src, std::list<int>& pairs);
	void	insertPowerTwoGroupsByBinarySearchInSubsequences(list& src, list& shorted, std::list<int>& pairs);
	list::iterator getIterator(list& src, unsigned int index);
	std::list<int>::iterator getIterator(std::list<int>& src, int index);
	int getIndex(list& src, list::iterator it);
};
std::ostream& operator << (std::ostream& os, const PmergeMe& src);

template <typename Container>
void isSorted(const Container& container)
{
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

#endif     //PMERGEME_H
