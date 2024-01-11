#include <Span.hpp>

Span::Span()
{
//Const
	maxNumbers = 0;
}

Span::~Span()
{
//Dest
}

Span::Span(const Span& src)
{
//Copy Const
	*this = src;
}

Span& Span::operator = (const Span& src)
{
	if (this != &src)
	{
		this->numbers = src.numbers;
		this->maxNumbers = src.maxNumbers;
	}
	return *this;
}
Span::Span(const unsigned int N)
{
	maxNumbers = N;
}

void Span::addNumber(const int &number)
{
	if (numbers.size() + 1 > maxNumbers)
		throw std::runtime_error("Span: trying to add more than N numbers.");
	numbers.push_back(number);
	maxNumbers++;
}

unsigned int Span::calculateSpan(bool (*comparador)(unsigned int, unsigned int)) const
{
	if (numbers.size() < 2)
		throw std::runtime_error("Span error: no span can be found");
	unsigned int span;
	unsigned int minSpan;
	std::list<int>::const_iterator prev = numbers.begin();
	std::list<int>::const_iterator it  = prev;
	it++;
	span = minSpan = std::abs(*prev - *it);
	while(it != numbers.end())
	{
		span = std::abs(*prev - *it);
		prev++;
		if (comparador(span,minSpan))
			minSpan = span;
		it++;
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

int Span::operator [] (std::size_t index) const
{
	if (index >= maxNumbers)
		throw std::runtime_error("Span: index out of N");
	std::size_t i = 0;
	std::list<int>::const_iterator it = numbers.begin();
	while(it != numbers.end() && i++ != index)
		it++;
	return *it;
}
