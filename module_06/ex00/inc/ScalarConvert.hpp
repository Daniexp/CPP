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
	void setInt();
	void setChar();
	void setFloat();
	void setDouble();
	bool checkError(int type, const std::string& expectResult);
	std::string getError(int type);
private:
	const std::string execArgument;
	char toChar;
	int toInt;
	float toFloat;
	double toDouble;
	std::string error[4];

	void convertStringToLiteral();
	void convertLiteralToScalarType();
};
std::ostream& operator << (std::ostream& os, const ScalarConvert& src);

#endif     //SCALARCONVERT_H
