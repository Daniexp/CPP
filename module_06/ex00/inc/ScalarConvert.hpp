#ifndef SCALARCONVERT_H
#define SCALARCONVERT_H

#include <iostream>
#include <string>
class ScalarConvert
{
public:
	ScalarConvert();
	ScalarConvert(const std::string& execArgument);
	~ScalarConvert();
   ScalarConvert(const ScalarConvert& src);
   ScalarConvert& operator=(const ScalarConvert& src);
	int getInt();
	char getChar();
	float getFloat();
	double getDouble();
private:
	const std::string& execArgument;
	int toInt;
	char toChar;
	float toFloat;
	double toDouble;

	void convertStringToLiteral();
	void convertLiteralToScalarTypes();
};
std::ostream& operator << (std::ostream& os, const ScalarConvert)
{
	return os;
}

#endif     //SCALARCONVERT_H
