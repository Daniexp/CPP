#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <iostream>
#include <string>
#include <list>
#include <stack>
#include <deque>

template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	MutantStack(){};
	~MutantStack(){};
   	MutantStack(const MutantStack& src){*this = src;};
   	MutantStack& operator=(const MutantStack& src)
	{
		std::stack<T, Container>::operator=(src);
	};
	typedef typename Container::iterator iterator;
	iterator begin() {return this->c.begin();};
	iterator end(){return this->c.end();};
private:

};

#endif     //MUTANTSTACK_H
