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
#include <iomanip>
#include <limits>
#include <cfloat>

class ScalarConvert
{
public:
	static void convert(const std::string& src);
	ScalarConvert(const std::string& execArgument);
	~ScalarConvert();
   ScalarConvert(const ScalarConvert& src);
   ScalarConvert& operator=(const ScalarConvert& src);
	int getInt() const;
	char getChar() const;
	float getFloat() const;
	double getDouble() const;
	int getType() const;
	const std::string& getExecArgument() const;
	void setInt();
	void setChar();
	void setFloat();
	void setDouble();
	void setType(int type);
	std::string getError(int type) const;
	void explicitCast();
private:
	ScalarConvert();
	static int saveType(const std::string& src, std::string error[]);
	static int isPseudoLiteral(const std::string& src, std::string error[]);

	std::string execArgument;
	unsigned char toChar;
	int toInt;
	float toFloat;
	double toDouble;
	std::string error[4];
	int	type;

void convertStringToLiteral();
void convertLiteralToScalarType();
void tryConvertToType(int type, void (ScalarConvert::*convertFunction)());
void charExplicitCast();
void intExplicitCast();
void floatExplicitCast();
void doubleExplicitCast();
int  isBiggerThanMaxInt();
int  isBiggerThanMaxFloat();
static int protectExplicitCast();
};
std::ostream& operator << (std::ostream& os,const ScalarConvert& src);

#endif     //SCALARCONVERT_H
