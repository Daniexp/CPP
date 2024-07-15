#ifndef RPN_HPP
#define RPN_HPP
# include <iostream>
# include <stack>
# include <string>

double	calculateRPN(const std::string& src);
double	calculateExpression(double nmb2, double nmb1, char op);
#endif
