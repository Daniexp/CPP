#ifndef BUREAUCRAFT_H
#define BUREAUCRAFT_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <AForm.hpp>
#include <GradeTooHighException.hpp>
#include <GradeTooLowException.hpp>

class AForm;

class Bureaucraft
{
public:
   Bureaucraft();
   Bureaucraft(const Bureaucraft& src);
   Bureaucraft(const std::string& _name, int _grade);
   ~Bureaucraft();
   Bureaucraft& operator=(const Bureaucraft& src);

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
std::ostream& operator << (std::ostream& os, const Bureaucraft& src);
#endif     //BUREAUCRAFT_H
