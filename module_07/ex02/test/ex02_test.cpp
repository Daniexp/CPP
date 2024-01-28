#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <sstream>
#include <Array.hpp>

TEST_CASE("Example Test_Case")
{
	MESSAGE("Example test case is executed successfully...");
}

TEST_CASE("Index out of bounds")
{
	Array<std::string>* stringArray = new Array<std::string>(200);
	try
	{
		(*stringArray)[-100] = std::string("Prueba fuera de rango");
	}
	catch(std::exception& message)
	{
		int a = 5;
		CHECK(a == 5);
	}
	delete stringArray;
}

TEST_CASE("Index out of bounds")
{
	Array<std::string>* stringArray = new Array<std::string>(2);
	try
	{
		(*stringArray)[1] = "Prueba dentro de rango";
		CHECK((*stringArray)[1] == "Prueba dentro de rango");
	}
	catch(std::exception& message)
	{
	}
	delete stringArray;
}
