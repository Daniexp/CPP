#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <RPN.hpp>
#include <iostream>
#include <sstream>
#include <doctest.h>

TEST_CASE("Subject examples")
{
	std::string argument = "8 9 * 9 - 9 - 9 - 4 - 1 +";
	CHECK(calculateRPN(argument) == 42);
	argument = "7 7 * 7 -";
	CHECK(calculateRPN(argument) == 42);
	argument = "1 2 * 2 / 2 * 2 4 - +";
	CHECK(calculateRPN(argument) == 0);
	argument = "8 9 * 9 - 9 - 9 - 4 - 1 +";
	CHECK(calculateRPN(argument) == 42);
	argument = "9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -";
	CHECK(calculateRPN(argument) == 42);
	argument = "1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /";
	CHECK(calculateRPN(argument) == 15);
}

TEST_CASE("Invalid arguments - Wrong argument expression")
{
	int size = 10;
	std::string inputs[] = {"+ 3 3", "3 - 3", "3 3", "5 5 .","5 5 A", "2 -2 *", "( 3 3 ) *", "[ 2 2 ] * 3 -", "hwejrwl iwojwif jfwof", "3 3 * *"};
	for (int i = 0; i < size; i++)
	{
		try
		{
			calculateRPN(inputs[i]);
		}catch (std::exception& e)
		{
			std::string err = e.what();
			CHECK(err == "Error");
		}
	}

}

TEST_CASE("Valid argumetns - results different than a positive integer")
{
	try
	{
	double res;
	std::string argument = "1 2 /";
	CHECK(calculateRPN(argument) == 0.5);
	argument = "0 1 - 2 /";
	res = calculateRPN(argument);
	CHECK(res == -0.5);
	argument = "7 0 20 - +";
	res = calculateRPN(argument);
	CHECK(res == -13);
	}catch (std::exception& e)
	{
		std::string err = e.what();
		CHECK("no debería fallar");
	}
	
}
