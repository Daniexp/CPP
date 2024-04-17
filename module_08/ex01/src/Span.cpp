#include <Span.hpp>
void addElement(Span& object, int number)
{
	//container.push_back(number);
	object.addNumber(number);
}	
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

void Span::addNumber(const int number)
{
	if (numbers.size() + 1 > maxNumbers)
		throw std::runtime_error("Span - trying to add more than N numbers");
	numbers.push_back(number);
	maxNumbers++;
}

template<typename iterator>
void Span::addNumbers(iterator first, iterator last)
{
	std::size_t newNumbers = last - first;
	if (numbers.size() + newNumbers > maxNumbers)
		throw std::runtime_error("Span - trying to add more than N numbers");
	for_each(first, last, addElement);
	maxNumbers += newNumbers;
}

//La menor distancia posible entre dos números en el vct es la menor distancia entre dos números consecutivos 
unsigned int Span::shortestSpan() const
{
	// to do
	return 100;
}

//La mayor distancia posible entre dos números del vct es maxElement - minElement
unsigned int Span::longestSpan() const
{
	return (*max_element(numbers.begin(), numbers.end()) - *min_element(numbers.begin(), numbers.end()));
}


int Span::operator [] (std::size_t index) const
{
	if (index >= maxNumbers)
		throw std::runtime_error("Span: index out of range");
	return numbers[index];
}
