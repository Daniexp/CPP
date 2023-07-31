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
	return *this;
}
