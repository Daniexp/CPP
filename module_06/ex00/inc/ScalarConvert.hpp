#ifndef SCALARCONVERT_H
#define SCALARCONVERT_H
#define INT 0
#define CHAR 1
#define isFloat 2
#define isDouble 3

#include <iostream>
#include <string>
class ScalarConvert
{
public:
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
	void setType();
	std::string getError(int type);
private:
	const std::string execArgument;
	char toChar;
	int toInt;
	float toFloat;
	double toDouble;
	std::string error[4];
	int	type;

	void convertStringToLiteral();
	void convertLiteralToScalarType();
};
std::ostream& operator << (std::ostream& os, const ScalarConvert& src);

#endif     //SCALARCONVERT_H
