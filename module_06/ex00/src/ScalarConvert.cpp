#include <ScalarConvert.hpp>

void ScalarConvert::convert(const std::string& src)
{
//Const
	std::string error[4];
	for (int i = 0; i < 4 ; i++)
		error[i] = "clean";
	int type = saveType(src, error);
	if (type == NOTYPE)
		return ;
//	convertLiteralToScalarType();
//	explicitCast();
	std::cout << "char: ";
	(error[CHAR] == "clean") ? std::cout << "elchar" : std::cout << error[CHAR];
	std::cout << std::endl << "int: ";
	(error[INT] == "clean") ? std::cout << "elint" : std::cout << error[INT];
	std::cout << std::endl << "float: ";
	(error[FLOAT] == "clean") ? std::cout << std::fixed << std::setprecision(1) << "elFloat" << "f" : std::cout << error[FLOAT];
	std::cout << std::endl << "double: ";
	(error[DOUBLE] == "clean") ? std::cout << std::fixed << std::setprecision(1) << "elDouble" : std::cout << error[DOUBLE];
	std::cout << std::endl;
}

ScalarConvert::ScalarConvert()
{
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
		for (int i = 0; i < 4 ; i++)
			this->error[i] = src.getError(i);
	}
	return *this;
}

const std::string& ScalarConvert::getExecArgument() const
{
	return this->execArgument;
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
int ScalarConvert::isPseudoLiteral(const std::string& src, std::string error[])
{
	std::string literals[] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	bool isLiteral = false;
	int type = NOTYPE;

	for (int i = 0; !isLiteral && i < 6; i++)
	{
		if (literals[i] == src)
		{
			if (i >= 0 && i <= 2)
			{
				error[FLOAT] = literals[i];
				error[DOUBLE] = literals[i + 3];
			}
			else
			{
				error[DOUBLE] = literals[i];
				error[FLOAT] = literals[i - 3];
			}
			isLiteral = true;
			error[CHAR] = error[INT] = "impossible";
			type = LITERAL;
		}
	}
	return type;
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
	std::cout << "char: ";
	(src.getError(CHAR) == "clean") ? std::cout << src.getChar() : std::cout << src.getError(CHAR);
	std::cout  << std::endl << "int: ";
	(src.getError(INT) == "clean") ? std::cout << src.getInt() : std::cout << src.getError(INT);
	std::cout << std::endl << "float: ";
	(src.getError(FLOAT) == "clean") ? std::cout << std::fixed << std::setprecision(1) << src.getFloat() << "f" : std::cout << src.getError(FLOAT);
	std::cout << std::endl << "double: ";
	(src.getError(DOUBLE) == "clean") ? std::cout << std::fixed << std::setprecision(1) << src.getDouble() : std::cout << src.getError(DOUBLE);
	std::cout << std::endl;

	return os;
}

void ScalarConvert::setType(int type)
{
	this->type = type;
}
int ScalarConvert::saveType(const std::string& src, std::string error[])
{
	int type = isPseudoLiteral(src, error);
	if (type == LITERAL)
		return type;
	int length =src.length();
	char* char_str = new char[length];
	std::strcpy(char_str,src.c_str());
	if (length == 1 && !isdigit(*char_str) && isascii(*char_str))
		type = (CHAR);
	delete[](char_str);

	std::string argument =src;
	int sign = (argument[0] == '-' || argument[0] == '+') ? 1 : 0;
	if (std::all_of((argument.begin() + sign), argument.end(), ::isdigit) == true)
		type = (INT);
	argument =src;
	int f_count = 0;
	int point = 0;
	for (int i = 0; i < (int) argument.size() && point == 0; i++)
	{
		if (argument[i] == '.')
		{
			point++;
			if ( i == 0 || std::all_of((argument.begin() + sign), argument.begin() + i, ::isdigit) == false)
				return type;
			for (int j = i + 1; j < (int) argument.size() && f_count == 0; j++)
				if (argument[j] == 'f')
				{
					f_count++;
					if (i + 1 == j)
						return type;
				}
		}
	}
	if (point == 1)
	{
		if (f_count  == 1 && argument.back() == 'f')
       			type = (FLOAT);
		else if (f_count == 0 && argument.front() != '.' && argument.back() != '.')
       		 	type = (DOUBLE);
	}
	return type;
}
int ScalarConvert::getType() const
{
	return this->type;
}

void ScalarConvert::convertLiteralToScalarType()
{
	switch (getType())
	{
		case CHAR:
			tryConvertToType(CHAR, &ScalarConvert::setChar);
		break;
		case INT:
			tryConvertToType(INT, &ScalarConvert::setInt);
		break;
		case FLOAT:
			tryConvertToType(FLOAT, &ScalarConvert::setFloat);
		break;
		case DOUBLE:
			tryConvertToType(DOUBLE, &ScalarConvert::setDouble);
		break;
	}
}
void ScalarConvert::tryConvertToType(int type, void (ScalarConvert::*convertFunction)(void))
{
	if (type == LITERAL || type == NOTYPE)
		return ;
	try
	{
		(this->*convertFunction)();
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
	this->toInt =  std::stoi(this->getExecArgument());
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
	this->toFloat = std::stof(this->getExecArgument().c_str());
}

void ScalarConvert::setDouble()
{
	if (getType() != DOUBLE)
		return ;
	this->toDouble = std::stod(this->getExecArgument().c_str());
}

void ScalarConvert::charExplicitCast()
{
	switch (this->getType())
	{
		case INT:
			this->toChar = static_cast<char>(this->getInt()); 
		break;
		case FLOAT:
			this->toChar = static_cast<char>(this->getFloat()); 
		break;
		case DOUBLE:
			this->toChar = static_cast<char>(this->getDouble()); 
		break;
	}
}
void ScalarConvert::intExplicitCast()
{
	switch (this->getType())
	{
		case CHAR:
			this->toInt = static_cast<int>(this->getChar()); 
		break;
		case FLOAT:
			this->toInt = static_cast<int>(this->getFloat()); 
		break;
		case DOUBLE:
			this->toInt = static_cast<int>(this->getDouble()); 
		break;
	}
}
void ScalarConvert::floatExplicitCast()
{
	switch (this->getType())
	{
		case CHAR:
			this->toFloat = static_cast<float>(this->getChar()); 
		break;
		case INT:
			this->toFloat = static_cast<float>(this->getInt()); 
		break;
		case DOUBLE:
			this->toFloat = static_cast<float>(this->getDouble()); 
		break;
	}
}
void ScalarConvert::doubleExplicitCast()
{
	switch (this->getType())
	{
		case CHAR:
			this->toDouble = static_cast<double>(this->getChar()); 
		break;
		case INT:
			this->toDouble = static_cast<double>(this->getInt()); 
		break;
		case FLOAT:
			this->toDouble = static_cast<double>(this->getFloat()); 
		break;
	}
}
int ScalarConvert::isBiggerThanMaxFloat()
{
	int res = 0;

	if ((getType() == DOUBLE && (getDouble() > FLT_MAX || getDouble() <  FLT_MIN)))
	{
		this->error[INT] = "impossible";
		this->error[CHAR] = "impossible";
		this->error[FLOAT] = "impossible";
		res = 1;
	}
	return res;
}
int ScalarConvert::isBiggerThanMaxInt()
{
	int res = 0;

	if ((getType() == DOUBLE && (getDouble() >  INT_MAX || getDouble() <  INT_MIN))
		|| (getType() == FLOAT && (getFloat() > (float)  INT_MAX || getFloat() <  INT_MIN)))
	{
		this->error[INT] = "impossible";
		this->error[CHAR] = "impossible";
		res = 1;
	}
	return res;
}

void ScalarConvert::explicitCast()
{
	int type = this->getType();
	if (type == NOTYPE || (!isBiggerThanMaxFloat() && !isBiggerThanMaxInt() && this->getError(type) != "clean"))
	{
		for(int i = 0; i < 4; i++)
			if (i != type)
				this->error[i] = "impossible";
		return;
	}
	tryConvertToType(CHAR, &ScalarConvert::charExplicitCast);
	tryConvertToType(INT, &ScalarConvert::intExplicitCast);
	tryConvertToType(FLOAT, &ScalarConvert::floatExplicitCast);
	tryConvertToType(DOUBLE, &ScalarConvert::doubleExplicitCast);
	if (getError(CHAR) == "clean")
	{
	    if (getInt() < CHAR_MIN || getInt() > CHAR_MAX)
	        this->error[CHAR] = "impossible";
	    else if (!std::isprint(getChar()))
	        this->error[CHAR] = "Non displayable";
	}

}

int ScalarConvert::protectExplicitCast()
{
	ScalarConvert arg;
	return (!arg.isBiggerThanMaxInt() && !arg.isBiggerThanMaxFloat());
}
