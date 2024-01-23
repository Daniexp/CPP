#include <ScalarConvert.hpp>

ScalarConvert::ScalarConvert()
{
}
ScalarConvert::~ScalarConvert()
{
}
ScalarConvert::ScalarConvert(const ScalarConvert& src)
{
	*this = src;

}
ScalarConvert& ScalarConvert::operator = (const ScalarConvert& src)
{
	if (this != &src)
		;
	return *this;
}
void ScalarConvert::convert(const std::string& src)
{
	int	valueInt = 0;
	char	valueChar;
	float	valueFloat = 0.0f;
	double	valueDouble = 0.0;
	std::string	error[4];

	for (int i = 0; i < 4 ; i++)
		error[i] = "clean";
	int type = saveType(src, error);
	try
	{
		switch(type)
		{
			case INT:
				valueInt =  std::stoi(src);
			break;
			case CHAR:
//				valueChar = *(src.c_str());
				valueChar = src.at(0);
			break;
			case FLOAT:
				valueFloat = std::stof(src.c_str());
			break;
			case DOUBLE:
				valueDouble = std::stod(src.c_str());
			break;
		}
	}
	catch (std::exception& message)
	{
		error[type] = "impossible";
	}
	if ( type != LITERAL && error[type] != "clean")
	{
		for(int i = 0; i < 4; i++)
			if (i != type)
				error[i] = "impossible";
	}
	if (!isBiggerThanMaxFloat(type, valueDouble, error))
		isBiggerThanMaxInt(type, valueDouble, valueFloat, error);
	switch(type)
	{
		case INT:
			valueChar = static_cast<char>(valueInt); 
			valueFloat = static_cast<float>(valueInt); 
			valueDouble = static_cast<double>(valueInt); 
		break;
		case CHAR:
			valueInt = static_cast<int>(valueChar);
			valueFloat = static_cast<float>(valueChar);
			valueDouble = static_cast<double>(valueChar);
		break;
		case FLOAT:
			valueChar = static_cast<char>(valueFloat);
			valueInt = static_cast<int>(valueFloat);
			valueDouble = static_cast<double>(valueFloat);
		break;
		case DOUBLE:
			valueInt = static_cast<int>(valueDouble);
			valueChar = static_cast<char>(valueDouble);
			valueFloat = static_cast<float>(valueDouble);
		break;
	}
	if (error[CHAR] == "clean")
	{
	    if (valueInt < 0 || valueInt < CHAR_MIN || valueInt > CHAR_MAX)
//		if (valueInt < 0 || valueInt > 255)
	       		error[CHAR] = "impossible";
		else if (!std::isprint(valueChar))
	        	error[CHAR] = "Non displayable";
	}
	printValues(error, valueChar, valueInt, valueDouble, valueFloat);
}

void ScalarConvert::printValues(std::string error[], char valueChar, int  valueInt, double valueDouble, float valueFloat)
{
	std::cout << "char: ";
	(error[CHAR] == "clean") ? std::cout << valueChar : std::cout << error[CHAR];
	std::cout << std::endl << "int: ";
	(error[INT] == "clean") ? std::cout << valueInt : std::cout << error[INT];
	std::cout << std::endl << "float: ";
	(error[FLOAT] == "clean") ? std::cout << std::fixed << std::setprecision(1) << valueFloat << "f" : std::cout << error[FLOAT];
	std::cout << std::endl << "double: ";
	(error[DOUBLE] == "clean") ? std::cout << std::fixed << std::setprecision(1) << valueDouble : std::cout << error[DOUBLE];
	std::cout << std::endl;
	
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
int ScalarConvert::saveType(const std::string& src, std::string error[])
{
	int type = isPseudoLiteral(src, error);
	if (type == LITERAL)
		return type;
	int length =src.length();
	char* char_str = new char[length];
	std::strcpy(char_str,src.c_str());
//	if (length == 1 && (int) *char_str >= 0 && (int) *char_str <= 255)
//	if (length == 1 && isascii(*char_str))//!isdigit(*char_str) && isascii(*char_str))
//	if (length == 1 && isascii(*char_str))
	if (length == 1 && isascii(src[0]) && !isdigit(src[0]))
//		return (delete[](char_str), CHAR);	
		return CHAR;
		//type = CHAR;
//	delete[](char_str);

	std::string argument = src;
	int sign = (argument[0] == '-' || argument[0] == '+') ? 1 : 0;
	if (std::all_of((argument.begin() + sign), argument.end(), ::isdigit) == true)
		return INT;
//		type = (INT);
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
int ScalarConvert::isBiggerThanMaxFloat(int type, double valueDouble, std::string error[])
{
	int res = 0;

	if ((type == DOUBLE && (valueDouble > (double) FLT_MAX || valueDouble <  (double) FLT_MIN)))
	{
		error[INT] = "impossible";
		error[CHAR] = "impossible";
		error[FLOAT] = "impossible";
		res = 1;
	}
	return res;
}
int ScalarConvert::isBiggerThanMaxInt(int type, double valueDouble, float valueFloat, std::string error[])
{
	int res = 0;

	if ((type == DOUBLE && (valueDouble >  (double) INT_MAX || valueDouble <  (double) INT_MIN))
		|| (type == FLOAT && (valueFloat > (float)  INT_MAX || valueFloat < (float) INT_MIN)))
	{
		error[INT] = "impossible";
		error[CHAR] = "impossible";
		res = 1;
	}
	return res;
}
