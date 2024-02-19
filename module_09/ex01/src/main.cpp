#include <RPN.hpp>

/*
void leaks(void)
{
	system("leaks ex01");
}
*/
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
int main(int argc, char **argv)
{
//	atexit(leaks);
	if (argc != 2)
		throw std::logic_error("Error");
	std::string argument = argv[1];
	//Save values in stack
	std::stack<char> expression = newInvertPolishExpression(argument);
	printStack(expression);
}
