#include <ScalarConvert.hpp>

ScalarConvert::ScalarConvert()
{
//Const
}

ScalarConvert::ScalarConvert(const std::string& execArgument) : execArgument(execArgument)
{
//Const
}

ScalarConvert::ScalarConvert(const ScalarConvert& src)
{
//Copy Const
	*this = src;
}

ScalarConvert::~ScalarConvert()
{
//Dest
}

ScalarConvert& ScalarConvert::operator = (const ScalarConvert& src)
{
	if (this != &src)
	{
	}
	return *this;
}

std::ostream& ScalarConvert::operator << (std::ostream& os, const ScalarConvert) 
{
	os << "char: " << getChar() << std::endl <<
		"int: " << getInt() << std::endl <<
		"float: " << getFloat() << std::endl <<
		"double: " << getDouble() << std::endl;

	return os;
}
