#ifndef SPAN_H
#define SPAN_H

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>

class Span
{
public:
	Span(const unsigned int N);
	Span();
	~Span();
   Span(const Span& src);
   Span& operator=(const Span& src);
	int operator[](std::size_t index) const;
	void addNumber(const int &number);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
	template<typename iterator>
void addNumbers(iterator first, iterator last)
{
	for (iterator it = first; it != last; it++)
		numbers.push_back(it);
}
private:
	unsigned int calculateSpan(bool (*comparador)(unsigned int, unsigned int)) const;
	static bool isLess(unsigned int a, unsigned int b);
	static bool isMore(unsigned int a, unsigned int b);
	unsigned int maxNumbers;
	std::list<int> numbers;
};

std::ostream& operator << (std::ostream& os, Span& src);

#endif     //SPAN_H
