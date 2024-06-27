#include <ex00.hpp>
#include <BitcoinExchange.hpp>

/*
void leaks(void)
{
	system("leaks ex00");
}
*/
int main(int argc, char *argv[])
{
//	atexit(leaks);
/*
	std::cout << "The proyect was created sucessfully." << std::endl;
	BitcoinExchange example;
	std::cout << example << std::endl;
//	example.printResults("input.txt");
	BitcoinExchange testDate("dataSimple.csv", "simpleInput.txt");
	std::cout << testDate << std::endl;
	testDate.printResults("simpleInput.txt");
*/
/*
	BitcoinExchange test = BitcoinExchange();
	std::cout << "emptyInput:" << std::endl;
	test.printResults("inputs/emptyInput.txt");
	std::cout << "onlySpaces:" << std::endl;
	test.printResults("inputs/onlySpaces.txt");
	std::cout << "noContent:" << std::endl;
	test.printResults("inputs/noContent.txt");
	std::cout << "input:" << std::endl;
	test.printResults("inputs/input.txt");
	std::cout << "inputSubject:" << std::endl;
	test.printResults("inputs/inputSubject.txt");
*/
	if (argc != 2)
		return -1;
	try
	{
		BitcoinExchange btcExchange = BitcoinExchange();
		btcExchange.printResults(argv[1]);
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
}
