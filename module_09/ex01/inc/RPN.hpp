#ifndef RPN_HPP
#define RPN_HPP
# include <iostream>
# include <stack>
# include <string>
typedef std::basic_string<char> str;

std::stack<char>	newInvertPolishExpression(const std::string& src);
long			calculatePolishExpression(std::stack<char>& expression);
long			calculateExpression(long* nmb2, long *nmb1, char *op);
bool			isNumber(char element);
void			printStack(std::stack<char>& expression);
#endif
