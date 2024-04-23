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

void Span::addNumber(const int number)
{
	if (numbers.size() + 1 > maxNumbers)
		throw std::runtime_error("Span - trying to add more than N numbers");
	numbers.push_back(number);
}

std::vector<int> Span::calculateSpans(void) const
{
	std::vector<int> differences;//(maxNumbers - 1);

	for (std::size_t i = 0; i + 1 < numbers.size(); i++)
		 differences.push_back(std::abs(numbers[i] - numbers[i + 1]));
	return (differences);
}
//La menor distancia posible entre dos números en el vct es la menor distancia entre dos números consecutivos 
unsigned int Span::shortestSpan() const
{
	// to do
	if (maxNumbers < 2)
		throw std::logic_error("Span - At least two numbers are required to get the shortestSpan.");
	std::vector<int> differences = calculateSpans();

	return (*min_element(differences.begin(), differences.end()));
}

//La mayor distancia posible entre dos números del vct es maxElement - minElement
unsigned int Span::longestSpan() const
{
	if (maxNumbers < 2)
		throw std::logic_error("Span - At least two numbers are required to get the longestSpan.");
	std::vector<int> differences = calculateSpans();

	return (*max_element(differences.begin(), differences.end()));
}


int Span::operator [] (std::size_t index) const
{
	if (index >= maxNumbers)
		throw std::runtime_error("Span: index out of range");
	return numbers[index];
}
std::ostream& operator << (std::ostream& os, Span& src)
{
	os << "Numbers: {";
	for (std::size_t i = 0; i < src.getNumbers().size(); i++)
		os << " " << src.getNumbers()[i];	
	os << "}" << std::endl;
	return os;
}
