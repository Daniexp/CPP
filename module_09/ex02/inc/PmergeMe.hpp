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
	void saveIntegerSequence(char* argv[], void saveMethod(void));
	void shortFirstContainer(std::vector<unsigned int>& src);
	void shortSecondContainer(std::list<unsigned int>& src);
	const std::vector<unsigned int> getFirstContainer(void) const;
	const std::list<unsigned int> getSecondContainer(void) const;
	void saveInfirstContainer(void);
	void saveInSecondContainer(void);
	void saveInAllContainers(void);

private:
	std::vector<unsigned int> firstContainer;
	std::list<unsigned int> secondContainer;
	 
};
std::ostream& operator << (std::ostream& os, const PmergeMe& src);
#endif     //PMERGEME_H
