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

PmergeMe& PmergeMe::operator = (const PmergeMe& src)
{
	if (this != &src)
	{
		this->firstContainer = src.firstContainer;
		this->secondContainer = src.secondContainer;
	}
	return *this;
}
/*
void PmergeMe::saveIntegerSequence(const std::vector<unsigned int>& src)
{
}

void PmergeMe::shortFirstContainer(std::vector<unsigned int>& src)
{
}

void PmergeMe::shortSecondContainer(std::list<unsigned int>& src)
{
}

std::ostream& operator << (std::osteram& os, const PmergeMe& src)
{
}
*/
