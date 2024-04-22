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
	void addNumber(const int number);
	std::vector<int> getNumbers(void)
	{
		return numbers;
	}
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
	template<typename iterator>
	void addNumbers(iterator first, iterator last)
{
	std::cout << "last - afist: " << last - first << std::endl;
	std::cout << "size + last - afist: " << numbers.size() + last - first << std::endl;
	std::cout << "maxNumbers " << maxNumbers << std::endl;
	if (numbers.size() + (last - first) > maxNumbers)
		throw std::runtime_error("Span - trying to add more than N numbers");
	for (iterator it = first; it != last; it++)
		numbers.push_back(*it);
	maxNumbers += last - first;
}
private:
	unsigned int calculateSpan(bool (*comparador)(unsigned int, unsigned int)) const;
	static bool isLess(unsigned int a, unsigned int b);
	static bool isMore(unsigned int a, unsigned int b);
	unsigned int maxNumbers;
	std::vector<int> numbers;
};

std::ostream& operator << (std::ostream& os, Span& src);

#endif     //SPAN_H
