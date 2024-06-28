#include <RPN.hpp>


int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw std::logic_error("Error");
		std::string argument = argv[1];
		std::stack<char> expression = newInvertPolishExpression(argument);
		std::cout << calculatePolishExpression(expression) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
