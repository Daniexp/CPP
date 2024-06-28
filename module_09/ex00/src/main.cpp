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
