
#include <ScalarConvert.hpp>
#include <iostream>
#include <string>
#ifndef DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

int main(int argc, char **argv)
{
	if (argc == 2)
		ScalarConvert::convert(argv[1]);
		//std::cout << ScalarConvert(argv[1]);
	return (0);
}

#endif
