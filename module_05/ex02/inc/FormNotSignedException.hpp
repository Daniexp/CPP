#ifndef FORMNOTSIGNEDEXCEPTION_H
#define FORMNOTSIGNEDEXCEPTION_H
#include <stdexcept>

class FormNotSignedException : public std::exception
{
	virtual const char * what() const throw();
};

#endif
