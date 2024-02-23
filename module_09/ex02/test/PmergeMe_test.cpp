#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <sstream>
#include <PmergeMe.hpp>

TEST_CASE("Example Test_Case")
{
	MESSAGE("Example test case is executed successfully...");
}

TEST_CASE("Test saveIntegerSequence")
{
	PmergeMe example;
	std::vector<unsigned int> sequence = {3, 5, 1 ,9};
	
	example.saveIntegerSequence(sequence);
	CHECK(example.getFirstContainer() == sequence);
}
