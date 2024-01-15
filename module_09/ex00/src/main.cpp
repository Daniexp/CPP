#include <ex00.hpp>
#include <BitcoinExchange.hpp>

/*
void leaks(void)
{
	system("leaks ex00");
}
*/
int main(void)
{
//	atexit(leaks);
	std::cout << "The proyect was created sucessfully." << std::endl;
	BitcoinExchange example;
	std::cout << example << std::endl;
//	example.printResults("input.txt");
	BitcoinExchange testDate("dataSimple.csv", "simpleInput.txt");
	std::cout << testDate << std::endl;
	testDate.printResults("simpleInput.txt");
}
