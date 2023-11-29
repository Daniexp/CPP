#include <ScalarConvert.hpp>

ScalarConvert::ScalarConvert(const std::string& execArgument) : execArgument(execArgument)
{
//Const
	saveType();
	convertLiteralToScalarType();
	explicitCast();
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
bool ScalarConvert::isPseudoLiteral()
{
	std::string literals[] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	bool isLiteral = false;
	this->setType(NOTYPE);

	for (int i = 0; !isLiteral && i < 6; i++)
	{
		if (literals[i] == this->getExecArgument())
		{
			if (i >= 0 && i <= 2)
			{
				this->error[FLOAT] = literals[i];
				this->error[DOUBLE] = literals[i + 3];
			}
			else
			{
				this->error[DOUBLE] = literals[i];
				this->error[FLOAT] = literals[i - 3];
			}
			isLiteral = true;
			this->error[CHAR] = this->error[INT] = "impossible";
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
	os << "char: ";
	(src.getError(CHAR) == "clean") ? os << src.getChar() : os << src.getError(CHAR);
	os  << std::endl << "int: ";
	(src.getError(INT) == "clean") ? os << src.getInt() : os << src.getError(INT);
	os << std::endl << "float: ";
	(src.getError(FLOAT) == "clean") ? os << std::fixed << std::setprecision(1) << src.getFloat() << "f" : os << src.getError(FLOAT);
	os << std::endl << "double: ";
	(src.getError(DOUBLE) == "clean") ? os << std::fixed << std::setprecision(1) << src.getDouble() : os << src.getError(DOUBLE);
	os << std::endl;

	return os;
}

void ScalarConvert::setType(int type)
{
	this->type = type;
}
void ScalarConvert::saveType()
{
	if (isPseudoLiteral() == true)
		return;
	int length = this->getExecArgument().length();
	char* char_str = new char[length];
	std::strcpy(char_str, this->getExecArgument().c_str());
	if (length == 1 && !isdigit(*char_str) && isascii(*char_str))
		setType(CHAR);
	delete[](char_str);

	std::string argument = this->getExecArgument();
	int sign = (argument[0] == '-' || argument[0] == '+') ? 1 : 0;
	if (std::all_of((argument.begin() + sign), argument.end(), ::isdigit) == true)
		setType(INT);
	argument = this->getExecArgument();
	int f_count = 0;
	int point = 0;
	for (int i = 0; i < (int) argument.size() && point == 0; i++)
	{
		if (argument[i] == '.')
		{
			point++;
			if ( i == 0 || std::all_of((argument.begin() + sign), argument.begin() + i, ::isdigit) == false)
				return ;
			for (int j = i + 1; j < (int) argument.size() && f_count == 0; j++)
				if (argument[j] == 'f')
				{
					f_count++;
					if (i + 1 == j)
						return ;
					if (std::all_of((argument.begin() + i + 1), argument.begin() + j, ::isdigit) == false)
						return ;
				}
		}
	}
	if (point == 1)
	{
		if (f_count  == 1 && argument.back() == 'f')
       			setType(FLOAT);
		else if (f_count == 0 && argument.front() != '.' && argument.back() != '.')
       		 	setType(DOUBLE);
	}
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
