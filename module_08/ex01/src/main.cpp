#include <Span.hpp>

void leaks(void)
{
	system("leaks -q ex01");
}

int main(void)
{
	atexit(leaks);

	Span sp = Span(10);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	std::vector<int> copy = sp.getNumbers();
	sp.addNumbers(copy.begin(), copy.end());
	Span sp2 = Span(1);
	sp2.addNumber(10);
	try
	{
			sp2.shortestSpan();
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
			sp2.longestSpan();
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
