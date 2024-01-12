#include <MutantStack.hpp>

MutantStack::MutantStack()
{
//Const
}

MutantStack::MutantStack(const MutantStack& src)
{
//Copy Const
	*this = src;
}

MutantStack::~MutantStack()
{
//Dest
}

MutantStack& MutantStack::operator = (const MutantStack& src)
{
	return *this;
}
