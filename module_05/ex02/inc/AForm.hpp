#ifndef AFORM_H
#define AFORM_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <GradeTooHighException.hpp>
#include <GradeTooLowException.hpp>
#include <Bureaucraft.hpp>

class Bureaucraft;

class AForm
{
public:

	AForm();
	~AForm();
   AForm(const AForm& src);
   AForm(const std::string& _name);
   AForm(const std::string& _name, const int exec, const int sign);
   AForm& operator=(const AForm& src);
	
   const std::string& getName() const;
   bool getIsSigned() const;
   int getExecGrade() const;
   int getSignGrade() const;

   void beSigned(const Bureaucraft& bureau);

private:
	const std::string name;
	bool isSigned;
	const int execGrade;
	const int signGrade;
};

std::ostream& operator << (std::ostream& os, const AForm& src);

#endif     //FORM_H
