#ifndef GRADETOOLOWEXCEPT_HPP
#define GRADETOOLOWEXCEPT_HPP
#include <iostream>
#include <string>
#include <stdexcept>

   class GradeTooLowExcept : public std::exception
	{
		virtual const char * what() const throw();
	};
#endif
