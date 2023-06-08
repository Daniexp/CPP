#include <FormNotSignedException.hpp>

const char * FormNotSignedException::what() const throw()
{
	return "The Form must be signed to execute it.\n";
}
