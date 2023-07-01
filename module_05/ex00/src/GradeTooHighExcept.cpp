#include <GradeTooHighExcept.hpp>

const char* GradeTooHighExcept::GradeTooHighExcept::what() const throw()
{
	return "The biggest valid Grade is 1\n";
}
