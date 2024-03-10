#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <sstream>
#include <PmergeMe.hpp>
/*
char **createArgumentArray(const std::size_t length)
{
	//char *ptr[length];
	char **ptr;
	for (std::size_t i = 0; length > i; i++)
		//ptr[i] = new (char*);
	return ptr;
}
*/
TEST_CASE("Example Test_Case")
{
	MESSAGE("Example test case is executed successfully...");
}
TEST_CASE("Test short by larger number of Pairs")
{
}
TEST_CASE("Test saveIntegerSequence")
{
	char* argv[4];
	argv[0] = new char;
	*argv[0] = '3';
	argv[1] = new char;
	*argv[1] = '5';
	argv[2] = new char;
	*argv[2] = '1';
	argv[3] = new char;
	*argv[3] = '9';
	PmergeMe example(argv);
	std::vector<unsigned int> sequence;
	sequence.insert(sequence.end(),3);
	sequence.insert(sequence.end(),5);
	sequence.insert(sequence.end(),1);
	sequence.insert(sequence.end(),9);
	const std::vector<unsigned int> saveSequence = example.getFirstContainer();
	CHECK(saveSequence[0] == sequence[0]);
	CHECK(saveSequence[1] == sequence[1]);
	CHECK(saveSequence[2] == sequence[2]);
	CHECK(saveSequence[3] == sequence[3]);
	std::list<unsigned int> saveSequence2 = example.getSecondContainer();
	CHECK(saveSequence2.front() == sequence[0]);
	saveSequence2.pop_front();
	CHECK(saveSequence2.front() == sequence[1]);
	saveSequence2.pop_front();
	CHECK(saveSequence2.front() == sequence[2]);
	saveSequence2.pop_front();
	CHECK(saveSequence2.front() == sequence[3]);
	saveSequence2.pop_front();

	for (int i = 0; i < 4 ; i++)
		delete argv[i];
}

TEST_CASE("Short valid integer sequence")
{
	char* argv[4];
	argv[0] = new char;
	*argv[0] = '3';
	argv[1] = new char;
	*argv[1] = '5';
	argv[2] = new char;
	*argv[2] = '1';
	argv[3] = new char;
	*argv[3] = '9';
	PmergeMe example(argv);
	std::vector<unsigned int> sequence;
	sequence.insert(sequence.end(),1);
	sequence.insert(sequence.end(),3);
	sequence.insert(sequence.end(),5);
	sequence.insert(sequence.end(),9);

	example.shortFirstContainer();
	
	const std::vector<unsigned int> saveSequence = example.getFirstContainer();
	CHECK(saveSequence[0] == sequence[0]);
	CHECK(saveSequence[1] == sequence[1]);
	CHECK(saveSequence[2] == sequence[2]);
	CHECK(saveSequence[3] == sequence[3]);

	for (int i = 0; i < 4 ; i++)
		delete argv[i];
}
