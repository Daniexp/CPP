#ifndef GRADETOOHIGHEXCEPT_HPP
#define GRADETOOHIGHEXCEPT_HPP
#include <iostream>
#include <string>
#include <stdexcept>

   class GradeTooHighExcept : public std::exception
	{
		virtual const char * what() const throw();
	};
#endif
