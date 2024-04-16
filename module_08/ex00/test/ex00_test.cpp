#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <sstream>
#include <easyfind.hpp>

TEST_CASE("easyfind - valid: search int on a int vtr")
{
	std::vector<int> vec;
	vec.push_back(1);
	try
	{
		 int value = *easyfind(vec, 1);
		 CHECK(value == 1);
	}
	catch (const std::exception& e)
	{
		CHECK("The element was find" == "The element wasn't find");
	}
}

TEST_CASE("easyfind - invalid: search int on a int vtr")
{
	std::vector<int> vec;
	vec.push_back(1);
	try
	{
		 int value = *easyfind(vec, 0);
		 CHECK(value == 1);
	}
	catch (const std::exception& e)
	{
		CHECK("The element wasn't find" == "The element wasn't find");
	}
}

TEST_CASE("easyfind - valid: search int on a char vtr")
{
	std::vector<char> vec;
	vec.push_back((int) 'X');
	try
	{
		 int value = *easyfind(vec, (int) 'X');
		 CHECK(value == (int) 'X');
	}
	catch (const std::exception& e)
	{
		CHECK("The element was find" == "The element wasn't find");
	}
}
