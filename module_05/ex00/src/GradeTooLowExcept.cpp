#include <GradeTooLowExcept.hpp>
const char* GradeTooLowExcept::GradeTooLowExcept::what() const throw()
{
	return "The Grade must be bigger than 0.\n";
}
