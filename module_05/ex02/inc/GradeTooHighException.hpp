#ifndef GRADETOOHIGHEXCEPTION_H
#define GRADETOOHIGHEXCEPTION_H

#include <iostream>
#include <string>
#include <stdexcept>
class GradeTooHighException : public std::exception
{
	virtual const char * what() const throw();
};

#endif     //GRADETOOHIGHEXCEPTION_H
