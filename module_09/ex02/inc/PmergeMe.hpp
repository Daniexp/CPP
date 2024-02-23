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
   PmergeMe(const PmergeMe& src);
   PmergeMe& operator=(const PmergeMe& src);
	void saveIntegerSequence(const std::vector<unsigned int>& src);
	void shortFirstContainer(std::vector<unsigned int>& src);
	void shortSecondContainer(std::list<unsigned int>& src);
	std::vector<unsigned int> getFirstContainer(void);
	std::list<unsigned int> getSecondContainer(void);

private:
	std::vector<unsigned int> firstContainer;
	std::list<unsigned int> secondContainer;
};
std::ostream& operator << (std::ostream& os, const PmergeMe& src);
#endif     //PMERGEME_H
