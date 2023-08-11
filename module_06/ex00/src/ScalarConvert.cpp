#include <ScalarConvert.hpp>

ScalarConvert::ScalarConvert(const std::string& execArgument) : execArgument(execArgument)
{
//Const
	setType();
	std::cout << getType() << std::endl;
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

void ScalarConvert::setType()
{
	// char 1 long y ascii
	// 	+ 1 length
	// 	is ascii 
	// ! No se pueden introducir no printeables  =>
	// 	ascii at least 2 digits
	// float
	//else if (this->execArgument.find("f") == this->execArgument.length())
	// 	.	opcional
	// 	f
	// double
	// 	.
	// 	no f
	// int
	// 	no . no f
	int negative = (getExecArgument()[0] == '-') ? 1 : 0;
	if (this->execArgument.size() == 1)
	{
		this->type = CHAR;
		setChar();
	}
	else if (this->execArgument.find("f") == this->execArgument.length())
		this->type = FLOAT;
	else if (this->execArgument.find(".") == std::string::npos)
		this->type = DOUBLE;
	else if (std::all_of(getExecArgument().begin() + negative, getExecArgument().end(), ::isdigit))
		this->type = INT;

}
int ScalarConvert::getType() const
{
	return this->type;
}

void ScalarConvert::setInt()
{
	if (getType() != INT)
	{
		this->error[1] = "notype";
		return ;
	}
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
	if (getType() != CHAR)
	{
		this->error[0] = "notype";
		return ;
	}
	this->toChar = static_cast<char>((int)*(this->getExecArgument().c_str()));
	if (getChar() >= 48 && getChar() <= 57)
	{
		this->error[0] ="notype";
		this->type = INT;
	}
	
}

void ScalarConvert::setFloat()
{
	if (getType() != FLOAT)
	{
		this->error[2] = "notype";
		return ;
	}
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
	
}

void ScalarConvert::setDouble()
{
	if (getType() != DOUBLE)
	{
		this->error[3] = "notype";
		return ;
	}
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
	std::cout << *this;
}

void ScalarConvert::convertLiteralToScalarType()
{
	setChar();
	setInt();
	setFloat();
	setDouble();
}
