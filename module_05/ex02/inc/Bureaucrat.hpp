#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <AForm.hpp>
#include <GradeTooHighException.hpp>
#include <GradeTooLowException.hpp>
#include <FormNotSignedException.hpp>

class AForm;

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

	void signForm(const AForm& form) const; 
	void executeForm(AForm const & form); 

	const std::string& getTarget(void) const;
private:
	const std::string name;
	int grade;
	const std::string target;
};
std::ostream& operator << (std::ostream& os, const Bureaucrat& src);
#endif     //BUREAUCRAT_H
