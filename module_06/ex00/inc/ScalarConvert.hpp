#ifndef SCALARCONVERT_H
#define SCALARCONVERT_H
#define INT	1
#define CHAR	0
#define FLOAT	2
#define DOUBLE	3
#define LITERAL	4
#define NOTYPE	5

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cfloat>

class ScalarConvert
{
public:
	static void convert(const std::string& src);
	~ScalarConvert();
	ScalarConvert& operator = (const ScalarConvert& src);
private:
	ScalarConvert();
	ScalarConvert(const ScalarConvert& src);
	static int saveType(const std::string& src, std::string error[]);
	static int isPseudoLiteral(const std::string& src, std::string error[]);
	static int  isBiggerThanMaxInt(int type, double valueDouble, float valueFloat, std::string error[]);
	static int  isBiggerThanMaxFloat(int type, double valueDouble, std::string error[]);
	static void printValues(std::string error[], char valueChar, int valueInt, double valueDouble, float valueFloat);
};

#endif     //SCALARCONVERT_H
