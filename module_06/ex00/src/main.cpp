
#include <ScalarConvert.hpp>
#include <iostream>
#include <string>
#ifndef DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
void printErrors(ScalarConvert src)
{
	for (int i = 0; i < 4 ; i++)
	{
		std::cout << "Error " << i << ": "  << src.getError(i) << std::endl;
	}
}

int main(void)
{
	std::cout << "The proyect was created sucessfully." << std::endl;
	ScalarConvert example = ScalarConvert("9");
	std::cout << example << std::endl;
	std::cout << "type: " << example.getType() << std::endl;
	printErrors(example);
	example = ScalarConvert("9999999.999999999");
	std::cout << example;
	example = ScalarConvert("100.000f");
	std::cout << example;
	example = ScalarConvert("-inff");
	std::cout << example;
}

#endif
