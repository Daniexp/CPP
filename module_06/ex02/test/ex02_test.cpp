#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <sstream>
#include <Base.hpp>
#include "../doctest/doctest/doctest.h"

TEST_CASE("Instanciate a Base class object")
{
	Base example; // Intenta crear una instancia de Base
	CHECK(true);
}

TEST_CASE("Check Generate method return pointer of Base class type")
{
	Base parentClass;
	bool res;
	if (parentClass.generate() != nullptr)
		res = true;
	CHECK(res);
}
