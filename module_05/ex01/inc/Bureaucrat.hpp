#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <Form.hpp>
#include <GradeTooHighException.hpp>
#include <GradeTooLowException.hpp>

class Form;

class Bureaucrat
{
public:
   Bureaucrat();
   Bureaucrat(const Bureaucrat& src);
   Bureaucrat(const std::string& _name, int _grade);
   ~Bureaucrat();
   Bureaucrat& operator=(const Bureaucrat& src);

   const std::string& getName(void) const;
   int	getGrade(void) const;
   void incrementGrade();
   void decrementGrade();

	void signForm(Form& form) const; 

private:
	const std::string name;
	int grade;
};
std::ostream& operator << (std::ostream& os, const Bureaucrat& src);
#endif     //BUREAUCRAFT_H
