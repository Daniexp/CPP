#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <sstream>
#include <iter.hpp>

TEST_CASE("Example Test_Case")
{
	MESSAGE("Example test case is executed successfully...");
}

TEST_CASE("Array of ints")
{
	std::ostringstream os;
	std::streambuf* old_cout_buf = std::cout.rdbuf(os.rdbuf());

	int array[5] = {-100, -50, 0, 50, 100};	

	iter<int, void (*)(int)>(array, 5, printElement);
	std::cout << std::endl;

	iter<int, void (*)(int&)>(array, 5, doubleElement);

	iter<int, void (*)(int)>(array, 5, printElement);
	std::cout << std::endl;
	std::cout.rdbuf(old_cout_buf);
	CHECK(os.str() == "-100 -50 0 50 100 \n-200 -100 0 100 200 \n");
}

TEST_CASE("Array of Strings")
{
	std::ostringstream os;
	std::streambuf* old_cout_buf = std::cout.rdbuf(os.rdbuf());

	std::string array[5] = {"A", "B", "C", "D", "E"};	

	iter<std::string, void (*)(std::string)>(array, 5, printElement);
	std::cout << std::endl;

	iter<std::string, void (*)(std::string&)>(array, 5, doubleElement);

	iter<std::string, void (*)(std::string)>(array, 5, printElement);
	std::cout << std::endl;
	std::cout.rdbuf(old_cout_buf);
	CHECK(os.str() == "A B C D E \nAA BB CC DD EE \n");
}
