#include <GradeTooLowException.hpp>

const char* GradeTooLowException::GradeTooLowException::what() const throw()
{
	return "The Lowest Grade is 150.\n";
}
