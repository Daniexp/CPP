#include <RPN.hpp>

double calculateRPN(const std::string& src)
{
	std::stack<double> expression;
	int size = (int) src.size();
	for (int i = 0; i < size; i++)
	{
		int ascii = src[i] - '\0';
		if (ascii != 32)
		{
			if (ascii > 47 && ascii < 58)
				expression.push(ascii - 48);
			else if ((ascii == 42 || ascii == 43 || ascii == 45 || ascii == 47) && expression.size() > 1)
			{
				double nmb1 = expression.top();
				expression.pop();
				double nmb2 = expression.top();
				expression.pop();
				expression.push(calculateExpression(nmb1, nmb2, src[i]));
			}
			else
				throw std::logic_error("Error");
		}
	}
	if (expression.size() != 1)
		throw std::logic_error("Error");
	return expression.top();
}

double calculateExpression(double nmb2, double nmb1, char op)
{
	double res;
	switch (op)
	{
		case '+':
		res = nmb1 + nmb2;
		break;
		case '-':
		res = nmb1 - nmb2;
		break;
		case '*':
		res = nmb1 * nmb2;
		break;
		case '/':
		res = nmb1 / nmb2;
		break;
	}
	return res;
}

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
