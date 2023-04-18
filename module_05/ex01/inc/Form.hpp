#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <GradeTooHighException.hpp>
#include <GradeTooLowException.hpp>

class Form
{
public:

	Form();
	~Form();
   Form(const Form& src);
   Form(const std::string& _name);
   Form(const std::string& _name, const int exec, const int sign);
   Form& operator=(const Form& src);
	
   const std::string& getName() const;
   bool getIsSigned() const;
   int getExecGrade() const;
   int getSignGrade() const;

   void beSigned();
   void signForm() const;

private:
	const std::string name;
	bool isSigned;
	const int execGrade;
	const int signGrade;
};

std::ostream& operator << (std::ostream& os, const Form& src);

#endif     //FORM_H
