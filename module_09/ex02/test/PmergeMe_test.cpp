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
	std::vector<unsigned int> sequence;
	sequence.insert(sequence.end(),3);
	sequence.insert(sequence.end(),5);
	sequence.insert(sequence.end(),1);
	sequence.insert(sequence.end(),9);
	
	CHECK(example.getFirstContainer() == sequence);
}
