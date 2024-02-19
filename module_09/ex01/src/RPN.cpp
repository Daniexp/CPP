#include <RPN.hpp>

std::stack<char> newInvertPolishExpression(const std::string& src)
{
	std::stack<char> expression;
	for (std::size_t i = 0; i < src.length(); i++)
	{
		while (src[i] == ' ')
			i++;
		if ((src[i] < '0' || src[i] > '9') && (src[i] == ',' || src[i] == '.'))
			throw std::logic_error("Error");
		expression.push(src[i]);
	}
	return expression;
}
/*
long calculateExpression(const std::stack<char>& expression)
{

}
*/
