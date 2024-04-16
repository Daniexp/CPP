#include <Span.hpp>

void leaks(void)
{
	system("leaks -q ex01");
}

int main(void)
{
	atexit(leaks);

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}
