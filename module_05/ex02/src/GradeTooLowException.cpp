#include <GradeTooLowException.hpp>

const char* GradeTooLowException::GradeTooLowException::what() const throw()
{
	return "The Grade must be bigger (1 is the biggest grade).\n";
}
