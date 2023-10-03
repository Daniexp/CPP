#include <ScalarConvert.hpp>

ScalarConvert::ScalarConvert(const std::string& execArgument) : execArgument(execArgument)
{
//Const
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
	this->setType(NOTYPE);

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

std::string ScalarConvert::getError(int type) const
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
		"double: " << src.getDouble() << std::endl << "type: " << src.getType() << " error char: " << src.getError(CHAR)<< std::endl;

	return os;
}

void ScalarConvert::setType(int type)
{
	this->type = type;
	std::cout << "type: " << type << "   set_type: " << this->type << std::endl;
}
void ScalarConvert::saveType()
{
//	setType(NOTYPE);
	if (isPseudoLiteral() == true)
		return;
	int length = this->getExecArgument().length();
	char* char_str = new char[length];
	std::strcpy(char_str, this->getExecArgument().c_str());
	if (length == 1 && !isdigit(*char_str) && isascii(*char_str))
	{
		setType(CHAR);
		return ;
	}
	delete[](char_str);

	std::string argument = this->getExecArgument();
	int sign = (argument[0] == '-' || argument[0] == '+') ? 1 : 0;
	if (std::all_of((argument.begin() + sign), argument.end(), ::isdigit) == true)
	{
		setType(INT);
		std::cout << "entra es un int" << "      " << getExecArgument()  << std::endl;
		return ;
	}
	argument = this->getExecArgument();
	if (/*argument.find('.') != std::string::npos && */argument.find("f") != std::string::npos)
	{
		setType(FLOAT);
		std::cout << "entra es un float" << "      " << getExecArgument()  << std::endl;
		return ;
	}
	if (argument.find('.') != std::string::npos && argument.find('f') == std::string::npos)
		setType(DOUBLE);
}
int ScalarConvert::getType() const
{
	return this->type;
}

void ScalarConvert::convertLiteralToScalarType()
{
	//		this->toChar = static_cast<char>(*(this->getExecArgument().c_str()));
	//		this->toInt =  std::stoi(this->getExecArgument());
	//		this->toFloat = static_cast<float>(std::stof(this->getExecArgument().c_str()));
	//		this->toDouble= static_cast<double>(std::stod(this->getExecArgument().c_str()));
	switch (getType())
	{
		case CHAR:
			setChar();
		break;
		case INT:
			setInt();
		break;
		case FLOAT:
			setFloat();
		break;
		case DOUBLE:
			setDouble();
		break;
	}
	std::cout << "type convertLiteralToScalarType " << getType() << std::endl;
	std::cout << "error char: " << getError(CHAR) << std::endl;
}
void ScalarConvert::tryConvertToType( void (*convertFunction) ())
{
	int type = getType();
	if (type == LITERAL || type == NOTYPE)
		return ;
	try
	{
		convertFunction();
	}
	catch(std::invalid_argument& message)
	{
		this->error[type] = "impossible";
	}
	catch(std::out_of_range& message)
	{
		this->error[type] = "out of range";
	}
	catch(std::exception& message)
	{
		this->error[type] = message.what();
	}
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
		this->toChar = *(this->getExecArgument().c_str());
}

void ScalarConvert::setFloat()
{
	if (getType() != FLOAT)
		return ;
	try
	{
		this->toFloat = std::stof(this->getExecArgument().c_str());
	}
	catch(std::invalid_argument& message)
	{
		this->error[2] = "impossible";
	}
	catch(std::out_of_range& message)
	{
		this->error[2] = "out of range";
	}
}

void ScalarConvert::setDouble()
{
	if (getType() != DOUBLE)
		return ;
	try
	{
		this->toDouble = std::stod(this->getExecArgument().c_str());
	}
	catch(std::invalid_argument& message)
	{
		this->error[3] = "impossible";
	}
	catch(std::out_of_range& message)
	{
		this->error[3] = "out of range";
	}
}

void ScalarConvert::explicitCast()
{
	switch (this->getType())
	{
		case CHAR:
			this->toInt = static_cast<int>(this->getChar());
			this->toFloat = static_cast<float>(this->getChar());
			this->toDouble = static_cast<double>(this->getChar());
		break;
		case INT:
			this->toChar = static_cast<char>(this->getInt());
			this->toFloat = static_cast<float>(this->getInt());
			this->toDouble = static_cast<double>(this->getInt());
			std::cout << "Entra en es int explicitCast" << std::endl;
		break;
		case FLOAT:
			std::cout << "Entra en es float explicitCast" << std::endl;
			this->toChar = static_cast<char>(this->getFloat());
			this->toInt = static_cast<int>(this->getFloat());
			this->toDouble = static_cast<double>(this->getFloat());
		break;
		case DOUBLE:
			this->toChar = static_cast<char>(this->getDouble());
			this->toFloat = static_cast<float>(this->getDouble());
			this->toInt = static_cast<int>(this->getDouble());
		break;
	}
		if (!std::isprint(getInt()))
		{
			(this->error)[CHAR] = "Non displayable";
			std::cout << "reconoce como no displaye" << std::endl;
		}
}
