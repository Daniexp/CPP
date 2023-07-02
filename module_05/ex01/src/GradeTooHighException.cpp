#include <GradeTooHighException.hpp>

const char* GradeTooHighException::GradeTooHighException::what() const throw()
{
	return "The Highest Grade is 1.\n";
}
