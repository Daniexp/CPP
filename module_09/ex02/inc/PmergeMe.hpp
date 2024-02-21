#ifndef PMERGEME_H
#define PMERGEME_H

#include <iostream>
#include <string>
class PmergeMe
{
public:
	PmergeMe();
	~PmergeMe();
   PmergeMe(const PmergeMe& src);
   PmergeMe& operator=(const PmergeMe& src);
private:

};

#endif     //PMERGEME_H
