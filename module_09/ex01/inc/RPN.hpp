#ifndef RPN_HPP
#define RPN_HPP
# include <iostream>
# include <stack>
# include <string>
typedef std::basic_string<char> str;

std::stack<char>	newInvertPolishExpression(const std::string& src);
long			calculateExpression(std::stack<char>& expression);
#endif
