#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <sstream>
#include <test.hpp>

TEST_CASE("Valid - serialize - data remains equals")
{
	testData* arg = startTest();
	
	CHECK(arg->convertData->x == 0);
	CHECK(arg->convertData->y == 0);
	CHECK(arg->convertData->add == 0);
	CHECK(arg->convertData->sub == 0);
	CHECK(arg->convertData->div == 0);
	CHECK(arg->convertData->mul == 0);
	
	endTest(arg);
}

TEST_CASE("Valid - Use the deserialize struct pointer Data")
{
	testData* arg = startTest();
	CHECK(arg->data.x == 0);
	CHECK(arg->data.y == 0);
	
	arg->convertData->x = -10;
	arg->convertData->y = 2;
	calcValues(arg->convertData);
	checkValues(arg->convertData, -8, -12, -20, -5);
}

TEST_CASE("Valid - Calc values with deserialize pointer and check with normal struct")
{
	testData* arg = startTest();
	CHECK(arg->data.x == 0);
	CHECK(arg->data.y == 0);
	
	arg->convertData->x = -10;
	arg->convertData->y = -2;
	calcValues(arg->convertData);
	checkValues(&arg->data, -12, -8, 20, 5);
}
