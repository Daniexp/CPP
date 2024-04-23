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
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::vector<int> copy = sp.getNumbers();
	std::cout << sp;
	sp.addNumbers(copy.begin(), copy.end());
	std::cout << sp;
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
}
