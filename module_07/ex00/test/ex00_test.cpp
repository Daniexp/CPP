#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "ex00.hpp"
#include "Object.hpp"
#include <iostream>
#include <sstream>

TEST_CASE("Example Test_Case")
{
	MESSAGE("Example test case is executed successfully...");
}

TEST_CASE("a = 2 && b = 3 - SUBJECT TEST")
{
	int a = 2;
	int b = 3;
	::swap(a, b);
	CHECK(a == 3);
	CHECK(b == 2);
	CHECK(::min(a,b) == 2);
	CHECK(::max(a,b) == 3);
}

TEST_CASE("a = chaine1 && b  = chaine2")
{
	std::string a = "chaine1";
	std::string b = "chaine2";
	::swap(a,b);
	CHECK(a == "chaine2");
	CHECK(b == "chaine1");
	CHECK(::min(a,b) == "chaine1");
	CHECK(::max(a,b) == "chaine2");
}
TEST_CASE("Class that supports all the comparison operations")
{
	Object a = Object(10);
	Object b = Object(-10);
	::swap(a,b);
	CHECK(a == -10);
	CHECK(b == 10);
	CHECK(::min(a,b) == -10);
	CHECK(::max(a,b) == 10);
}

/*
TEST_CASE("a and b with different types")
{
	int a = 100;
	std::string b = "chaine2";
	::swap(a,b);
	CHECK(a == "chaine2");
	CHECK(b == "chaine1");
	CHECK(::min(a,b) == "chaine1");
	CHECK(::max(a,b) == "chaine2");
}
*/
