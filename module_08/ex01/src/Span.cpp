#include <Span.hpp>

Span::Span() : std::list<int>(0)
{
//Const
	numbers = 0;
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
		std::list<int>::operator=(src);
	}
	return *this;
}
Span::Span(const unsigned int N)// : std::list<int>(N)
{
	numbers = N;
}

void Span::addNumber(const int &number)
{
	if (this->size() + 1 > numbers)
		throw std::runtime_error("Span: trying to add more than N numbers.");
	this->push_back(number);
//	std::list<int>::operator[](numbers) = number;
//	(*this)[numbers] = number;
//	numbers++;
}

unsigned int Span::calculateSpan(bool (*comparador)(unsigned int, unsigned int)) const
{
	if (this->size() < 2)
		throw std::runtime_error("Span error: no span can be found");
	unsigned int span;
	unsigned int minSpan = 0;
	std::list<int>::const_iterator prev = this->begin();
	std::list<int>::const_iterator it  = prev;
	it++;
	while(it != this->end())
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
