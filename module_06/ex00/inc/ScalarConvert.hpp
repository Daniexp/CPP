#ifndef SCALARCONVERT_H
#define SCALARCONVERT_H

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
	const std::string& getExecArgument() const;
private:
	const std::string& execArgument;
	int toInt;
	char toChar;
	float toFloat;
	double toDouble;

	void convertStringToLiteral();
	void convertLiteralToScalarTypes();
};
std::ostream& operator << (std::ostream& os, const ScalarConvert& src);

#endif     //SCALARCONVERT_H
