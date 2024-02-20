#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <RPN.hpp>
#include <iostream>
#include <sstream>
#include <doctest.h>

TEST_CASE("Example Test_Case")
{
	MESSAGE("Example test case is executed successfully...");
}

TEST_CASE("Subject examples")
{
	std::string argument = "8 9 * 9 - 9 - 9 - 4 - 1 +";
	std::stack<char> expression = newInvertPolishExpression(argument);
	CHECK(calculatePolishExpression(expression) == 42);
	argument = "7 7 * 7 -";
	expression = newInvertPolishExpression(argument);
	CHECK(calculatePolishExpression(expression) == 42);
	argument = "1 2 * 2 / 2 * 2 4 - +";
	expression = newInvertPolishExpression(argument);
	CHECK(calculatePolishExpression(expression) == 0);
}

TEST_CASE("Invalid arguments - Wrong argument expression")
{
	int size = 5;
	std::string inputs[] = {"+ 3 3", "3 - 3", "3 3", "5 5 .","5 5 A"};
	std::stack<char> expression;
	for (int i = 0; i < size; i++)
	{
		try
		{
			expression = newInvertPolishExpression(inputs[i]);
			calculatePolishExpression(expression);
		}catch (std::exception& e)
		{
			std::string err = e.what();
			CHECK(err == "Error");
		}
	}

}
