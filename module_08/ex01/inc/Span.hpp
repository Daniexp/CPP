#ifndef SPAN_H
#define SPAN_H

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

class Span : public std::vector<int>
{
public:
	Span(const unsigned int N);
/*
	Span();
	~Span();
   Span(const Span& src);
   Span& operator=(const Span& src);
*/
	void addNumber(const int &number);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
	template<typename iterator>
void addNumbers(iterator first, iterator last)
{
	this->insert(this->end(), first, last);
}
private:
	unsigned int calculateSpan(bool (*comparador)(unsigned int, unsigned int)) const;
	static bool isLess(unsigned int a, unsigned int b);
	static bool isMore(unsigned int a, unsigned int b);
};

#endif     //SPAN_H
