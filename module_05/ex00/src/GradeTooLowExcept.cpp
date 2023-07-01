#include <GradeTooLowExcept.hpp>
const char* GradeTooLowExcept::GradeTooLowExcept::what() const throw()
{
	return "The smallest valid Grade is 150\n"; 
}
