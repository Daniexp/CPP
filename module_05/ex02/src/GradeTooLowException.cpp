#include <GradeTooLowException.hpp>

const char* GradeTooLowException::GradeTooLowException::what() const throw()
{
	return "The Grade must be bigger than 0.\n";
}
