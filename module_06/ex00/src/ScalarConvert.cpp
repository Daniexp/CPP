#include <ScalarConvert.hpp>

ScalarConvert::ScalarConvert(const std::string& execArgument) : execArgument(execArgument)
{
//Const
//	setType();
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

std::string ScalarConvert::getError(int type)
{
	std::string actualResult;
	if (type >= 0 && type <= 3)
		actualResult = this->error[type];
	if (actualResult.length() == 0)
		actualResult = "clean";
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

void ScalarConvert::setType(int type)
{
	this->type = type;
}
int ScalarConvert::getType() const
{
	return this->type;
}

void ScalarConvert::setInt()
{
	std::string argument = this->getExecArgument();
	int negative = (argument[0] == '-' || argument[0] == '+') ? 1 : 0;
	if (!std::all_of(argument.begin() + negative, argument.end(), ::isdigit))
		return ;
	try
	{
		this->toInt =  std::stoi(this->getExecArgument());
	}
	catch(std::invalid_argument& message)
	{
		this->error[1] = "impossible";
	}
	catch(std::out_of_range& message)
	{
		this->error[1] = "out of range";
	}
	setType(INT);
}

void ScalarConvert::setChar()
{
	int length = this->getExecArgument().length();
	char* char_str = new char[length];
	std::strcpy(char_str, this->getExecArgument().c_str());
	if (length == 1 || isascii(*char_str))
		this->toChar = *char_str;
	delete[](char_str);
	setType(CHAR);
}

void ScalarConvert::setFloat()
{
	std::string argument = this->getExecArgument();
	if (argument.find('.') == std::string::npos || argument.find('f') == std::string::npos)
		return ;
	try
	{
		this->toFloat = static_cast<float>(std::stof(this->getExecArgument().c_str()));
	}
	catch(std::invalid_argument& message)
	{
		this->error[2] = "impossible";
	}
	catch(std::out_of_range& message)
	{
		this->error[2] = "out of range";
	}
	setType(FLOAT);
}

void ScalarConvert::setDouble()
{
	std::string argument = this->getExecArgument();
	if (argument.find('.') == std::string::npos || argument.find('f') != std::string::npos)
		return ;
	try
	{
		this->toDouble= static_cast<double>(std::stod(this->getExecArgument().c_str()));
	}
	catch(std::invalid_argument& message)
	{
		this->error[3] = "impossible";
	}
	catch(std::out_of_range& message)
	{
		this->error[3] = "out of range";
	}
	setType(DOUBLE);
}

void ScalarConvert::convertLiteralToScalarType()
{
	setChar();
	setInt();
	setFloat();
	setDouble();
}
