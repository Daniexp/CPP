#include <ScalarConvert.hpp>

ScalarConvert::ScalarConvert(const std::string& execArgument) : execArgument(execArgument)
{
//Const
	this->type = 0;
	saveType();
	convertLiteralToScalarType();
	explicitCast();
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
bool ScalarConvert::isPseudoLiteral()
{
	std::string literals[] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	bool isLiteral = false;

	for (int i = 0; !isLiteral && i < 6; i++)
	{
		if (literals[i] == this->getExecArgument())
		{
			isLiteral = true;
			this->setType(LITERAL);
		}
	}
	return isLiteral;
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
void ScalarConvert::saveType()
{
	int length = this->getExecArgument().length();
	char* char_str = new char[length];
	std::strcpy(char_str, this->getExecArgument().c_str());
	if (length == 1 && !isdigit(*char_str) && isascii(*char_str))
		this->type = CHAR;
	delete[](char_str);

	std::string argument = this->getExecArgument();
	int negative = (argument[0] == '-' || argument[0] == '+') ? 1 : 0;
	if (std::all_of(argument.begin() + negative, argument.end(), ::isdigit))
		setType(INT);

}
int ScalarConvert::getType() const
{
	return this->type;
}

void ScalarConvert::setInt()
{
	if (this->getType() != INT)
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
}

void ScalarConvert::setChar()
{
	if (getType() == CHAR)
		this->toChar = static_cast<char>(*(this->getExecArgument().c_str()));
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
void ScalarConvert::explicitCast()
{
	if (this->getType() == CHAR)
	{
		this->toInt = this->getChar();
		this->toFloat = this->getChar();
		this->toDouble = this->getChar();
	}
	else if (this->getType() == INT)
	{
		this->toChar = this->getInt();
		this->toFloat= this->getInt();
		this->toDouble= this->getInt();
	}
	else if (this->getType() == FLOAT)
	{
		this->toChar = this->getFloat();
		this->toFloat= this->getFloat();
		this->toDouble= this->getFloat();
	}
	else if (this->getType() == DOUBLE)
	{
		this->toChar = this->getDouble();
		this->toFloat= this->getDouble();
		this->toDouble= this->getDouble();
	}
}
