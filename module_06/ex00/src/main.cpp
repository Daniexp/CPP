
#include <ScalarConvert.hpp>
#include <iostream>
#include <string>
#ifndef DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
int main(void)
{
	std::cout << "The proyect was created sucessfully." << std::endl;
	ScalarConvert example = ScalarConvert("0");
	std::cout << example << std::endl;
}
#endif
