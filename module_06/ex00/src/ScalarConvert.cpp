#include <ScalarConvert.hpp>

ScalarConvert::ScalarConvert(const std::string& execArgument) : execArgument(execArgument)
{
//Const
	convertLiteralToScalarType();
}

ScalarConvert::ScalarConvert(const ScalarConvert& src) : execArgument(src.getExecArgument())
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
		this->toChar = src.getChar();
		this->toInt = src.getInt();
		this->toFloat = src.getFloat();
		this->toDouble = src.getDouble();
	}
	return *this;
}

const std::string& ScalarConvert::getExecArgument() const
{
	return execArgument;
}

int ScalarConvert::getInt() const
{
	return  toInt;
}

char ScalarConvert::getChar() const
{
	return toChar;
}

float ScalarConvert::getFloat() const
{
	return toFloat;
}

double ScalarConvert::getDouble() const
{
	return toDouble;
}
bool ScalarConvert::checkError(int type, const std::string& expectResult)
{
	std::string actualResult;
	if (type >= 0 && type <= 3)
		actualResult = this->error[type];
	return (type >= 0 && type <= 3 && expectResult == actualResult);	
}
std::string ScalarConvert::getError(int type)
{
	std::string actualResult;
	if (type >= 0 && type <= 3)
		actualResult = this->error[type];
	else
		actualResult = "No error detected.";
	return actualResult;
}

std::ostream& operator << (std::ostream& os, const ScalarConvert& src) 
{
	os << "char: " << src.getChar() << std::endl <<
		"int: " << src.getInt() << std::endl <<
		"float: " << src.getFloat() << std::endl <<
		"double: " << src.getDouble() << std::endl;

	return os;
}
void ScalarConvert::setInt()
{
	try
	{
		this->toInt = std::stoi(this->getExecArgument());
	}
	catch(std::invalid_argument& message)
	{
		this->error[1] = "impossible";
	}
	catch(std::out_of_range& message)
	{
		this->error[1] = "out of range";
	}
}

void ScalarConvert::convertLiteralToScalarType()
{
	setInt();
}
