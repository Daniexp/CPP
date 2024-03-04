#ifndef PMERGEME_H
#define PMERGEME_H

#include <iostream>
#include <string>
#include <vector>
#include <list>

class PmergeMe
{
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(char* argv[]);
   PmergeMe(const PmergeMe& src);
   PmergeMe& operator=(const PmergeMe& src);
	const std::vector<unsigned int> getFirstContainer(void) const;
	const std::list<unsigned int> getSecondContainer(void) const;

	void shortFirstContainer();
	void shortSecondContainer(std::list<unsigned int>& src);

private:
	void saveIntegerSequence(char* argv[], void saveMethod(void));
	void saveInfirstContainer(void);
	void saveInSecondContainer(void);
	void saveInAllContainers(void);

	void shortLargerElements(std::vector<unsigned int>& src, int start, int end);
	void binarySearchInsertionVector(std::vector<unsigned int>& src, const unsigned int value, int start, int end);

	std::vector<unsigned int> firstContainer;
	std::list<unsigned int> secondContainer;
	 
};
std::ostream& operator << (std::ostream& os, const PmergeMe& src);
#endif     //PMERGEME_H
