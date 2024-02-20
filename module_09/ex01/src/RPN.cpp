#include <RPN.hpp>

std::stack<char> newInvertPolishExpression(const std::string& src)
{
	std::stack<char> expression;
	for (int i = src.length() - 1; i >= 0; i--)
	{
		while (src[i] == ' ')
			i--;
		if (src[i] < '*' || src[i] > '9' || src[i] == ',' || src[i] == '.')
			throw std::logic_error("Error");
		expression.push(src[i]);
	}
	return expression;
}

long calculatePolishExpression(std::stack<char>& expression)
{
	long nmb1, nmb2;
	char top;
	std::stack<long> result;
	while (expression.empty() == false)
	{
		top = expression.top();
		expression.pop();
		if (isNumber(top))
			result.push(top - '0');
		else if(result.size() < 2)
			throw std::logic_error("Error");
		else
		{
			nmb1 = result.top();
			result.pop();
			nmb2 = result.top();
			result.pop();
			result.push(calculateExpression(&nmb1, &nmb2, &top));
		}
	}
	if (result.size() != 1)
		throw std::logic_error("Error");
	return result.top();
}

long calculateExpression(long* nmb2, long* nmb1, char *op)
{
	long res;
	switch (*op)
	{
		case '+':
		res = *nmb1 + *nmb2;
		break;
		case '-':
		res = *nmb1 - *nmb2;
		break;
		case '*':
		res = *nmb1 * *nmb2;
		break;
		case '/':
		res = *nmb1 / *nmb2;
		break;
	}
	return res;
}

bool isNumber(char element)
{
	return (element >= '0' && element <= '9');
}

void printStack(std::stack<char>& expression)
{
	if (expression.empty())
		return;
	char content = expression.top();
	expression.pop();
	printStack(expression);
	expression.push(content);
	std::cout << content << std::endl;
}
