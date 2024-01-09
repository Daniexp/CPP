#include <Span.hpp>
/*
Span::Span()
{
//Const
}

Span::Span(const Span& src)
{
//Copy Const
	*this = src;
}

Span::~Span()
{
//Dest
}

Span& Span::operator = (const Span& src)
{
	return *this;
}
*/
Span::Span(const unsigned int N) : std::vector<int>(N)
{
}

void Span::addNumber(const int &number)
{
	this->push_back(number);
}

unsigned int Span::calculateSpan(bool (*comparador)(unsigned int, unsigned int)) const
{
	if (this->size() < 2)
		throw std::runtime_error("Span error: no span can be found");
	unsigned int span;
	unsigned int minSpan = 0;
	std::vector<int>::const_iterator prev = this->begin();
	for (std::vector<int>::const_iterator it  = prev + 1; it != this->end(); it++)
	{
		span = std::abs(*prev - *it);
		prev++;
		if (comparador(span,minSpan))
			minSpan = span;
	}
	return minSpan;
}

unsigned int Span::shortestSpan() const
{
	return calculateSpan(&isLess);
}

unsigned int Span::longestSpan() const
{
	return calculateSpan(&isMore);
}

bool Span::isLess(unsigned int a, unsigned int b)
{
	return a < b;
}

bool Span::isMore(unsigned int a, unsigned int b)
{
	return a > b;
}
