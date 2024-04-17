#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <sstream>
#include <Span.hpp>

TEST_CASE("Example Test_Case")
{
	MESSAGE("Example test case is executed successfully...");
}

TEST_CASE("Canonical form of Span class")
{
	Span example = Span(1);
	example.addNumber(1);

	Span comparatorOperator = example;
	Span byCopyConstructor(example);
	
	CHECK(example[0] == comparatorOperator[0]);
	CHECK(example[0] == byCopyConstructor[0]);
	Span defaultConstructor = Span();
	Span* dynamicSpan = new Span();
	delete dynamicSpan;
}

TEST_CASE("Valid - addNumber")
{
	Span example = Span(1);
	example.addNumber(-1);
	CHECK(example[0] == -1);
}
TEST_CASE("Valid - addNumbers")
{
	std::vector<int> numbers;
	numbers.push_back(2);
	numbers.push_back(1);
	numbers.push_back(-1);
	numbers.push_back(-2);
	Span example = Span(4);
	example.addNumbers(numbers.begin(), numbers.end());
	CHECK(example[0] == 2);
	CHECK(example[1] == 1);
	CHECK(example[2] == -1);
	CHECK(example[3] == -2);
}

TEST_CASE("Invalid - addNumber")
{
	try
	{
		Span example = Span(0);
		example.addNumber(-1);
	}
	catch(std::exception& e)
	{
		CHECK(std::string(e.what()) == "Span - trying to add more than N numbers");
	}
}

TEST_CASE("Valid - shortestSpan and longestSpan")
{
	Span example = Span(4);
	example.addNumber(-1);
	example.addNumber(1);
	example.addNumber(-5);
	example.addNumber(5);
	
	CHECK(example.shortestSpan() == 2);
	CHECK(example.longestSpan() == 10);
}

TEST_CASE("Invalid - shortestSpan and longestSpan")
{
	Span example = Span(4);
	example.addNumber(-1);
	example.addNumber(1);
	example.addNumber(-5);
	example.addNumber(5);
	try
	{
		example.shortestSpan();
	}
	catch (std::exception& e)
	{
		CHECK(e.what() == "Span - no span can be found");
	}
	try
	{
		example.longestSpan();
	}
	catch (std::exception& e)
	{
		CHECK(e.what() == "Span - no span can be found");
	}
}
