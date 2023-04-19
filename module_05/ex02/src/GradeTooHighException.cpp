#include <GradeTooHighException.hpp>

const char* GradeTooHighException::GradeTooHighException::what() const throw()
{
	return "The Grade must be smaller than 150.\n";
}
