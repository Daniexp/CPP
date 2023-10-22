#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <sstream>
#include <Base.hpp>

TEST_CASE("Instanciate a Base class object")
{
	Base example; // Intenta crear una instancia de Base
	CHECK(true);
}

TEST_CASE("Check Generate method return pointer of Base class type")
{
	bool res;
	if (generate() != nullptr)
		res = true;
	CHECK(res);
}

TEST_CASE("identify(Base* p) Valid pointer")
{
	std::ostringstream outStream;
	std::streambuf* oldOut = std::cout.rdbuf(outStream.rdbuf());
	Base* derivateClass = new A;

	identify(derivateClass);
	outStream.str(outStream.str().substr(0, outStream.str().size() - 1));
	std::cout.rdbuf(oldOut);
	CHECK(outStream.str() == "A");
	std::cout.rdbuf(outStream.rdbuf());
	delete derivateClass;

	derivateClass = new B;
	identify(derivateClass);
	outStream.str(outStream.str().substr(0, outStream.str().size() - 1));
	std::cout.rdbuf(oldOut);
	CHECK(outStream.str() == "B");
	std::cout.rdbuf(outStream.rdbuf());
	delete derivateClass;

	derivateClass = new C;
	identify(derivateClass);
	outStream.str(outStream.str().substr(0, outStream.str().size() - 1));
	std::cout.rdbuf(oldOut);
	CHECK(outStream.str() == "C");
	delete derivateClass;
}

TEST_CASE("identify(Base* p) Invalid pointer")
{
	std::ostringstream outStream;
	std::streambuf* oldOut = std::cout.rdbuf(outStream.rdbuf());

	Base* parentClass = new Base;
	identify(parentClass);
	outStream.str(outStream.str().substr(0, outStream.str().size() - 1));
	std::cout.rdbuf(oldOut);
	CHECK(outStream.str() == "ERROR: invalid argument");

	delete parentClass;
}
/*
	std::ostringstream outStream;
	std::streambuf* oldOut = std::cout.rdbuf(outStream.rdbuf());
	Base parentClass;
	Base* randomClass = parentClass.generate();

	delete randomClass;
	std::cout.rdbuf(oldOut);
*/
