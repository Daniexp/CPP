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
	
	CHECK(example[0] == comparatorOperator[1]);
	CHECK(example[0] == byCopyConstructor[1]);
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
