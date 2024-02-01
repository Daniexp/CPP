#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <BitcoinExchange.hpp>
#include <iostream>
#include <sstream>

std::string exercisePath = "/Users/dexposit/Documents/CPP/module_09/ex00/inputs/";

TEST_CASE("Example Test_Case")
{
	MESSAGE("Example test case is executed successfully...");
}

TEST_CASE("Instanciate an ExchangeBitcoin class")
{
	BitcoinExchange bst = BitcoinExchange();
}

TEST_CASE("Invalid - INPUT FILE empty")
{
	BitcoinExchange bst = BitcoinExchange();
	bst.printResults(exercisePath + "emptyInput.txt");
}
TEST_CASE("Invalid - INPUT FILE with only spaces")
{
	BitcoinExchange bst = BitcoinExchange();
	bst.printResults(exercisePath + "onlySpaces.txt");
}
