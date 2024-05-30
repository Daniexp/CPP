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
	const std::list<unsigned int> getSecondContainer(void) const;

	void shortFirstContainer();
	void shortSecondContainer(std::list<unsigned int>& src);

private:
	void saveIntegerSequence(char* argv[], void saveMethod(void));
	void saveInfirstContainer(void);
	void saveInSecondContainer(void);
	void saveInAllContainers(void);

	void binarySearchInsertionVector(vector& S, const unsigned int srcValue, int start, int end);

	void swap(unsigned int& nmb1, unsigned int& nmb2);

	vector firstContainer;
	std::list<unsigned int> secondContainer;
	const vector originalSequence;

	void shortPairs(vector& src);
	void splitPairs(vector& src, vector& shorted);
	void orderBiggestPairs(vector& shorted, vector& src);
	std::vector<int> savePairsOfUnshorted(vector& src, vector& shorted);
	void	reverseUnshortedPairsInGroupsOfPowerTwo(vector& src, std::vector<int>& pairs);
	void	insertPowerTwoGroupsByBinarySearchInSubsequences(vector& src, vector& shorted, std::vector<int>& pairs);
};
std::ostream& operator << (std::ostream& os, const PmergeMe& src);
#endif     //PMERGEME_H
