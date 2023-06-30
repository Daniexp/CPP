#include <GradeTooHighExcept.hpp>

const char* GradeTooHighExcept::GradeTooHighExcept::what() const throw()
{
	return "The Grade must be smaller than 150.\n";
}
