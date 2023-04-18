#ifndef GRADETOOLOWEXCEPTION_H
#define GRADETOOLOWEXCEPTION_H

#include <iostream>
#include <string>
#include <stdexcept>

class GradeTooLowException : public std::exception
{
	virtual const char * what() const throw();
};

#endif     //GRADETOOLOWEXCEPTION_H
