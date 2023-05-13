#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include <iostream>
#include <string>
#include <Bureaucraft.hpp>
#include <stdexcept>
#include <GradeTooLowException.hpp>
#include <GradeTooHighException.hpp>
#include <AForm.hpp>

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm(const std::string& target);
	~PresidentialPardonForm();
   	PresidentialPardonForm(const PresidentialPardonForm& src);
   PresidentialPardonForm& operator=(const PresidentialPardonForm& src);

   	virtual void doAction(const std::string& target) const;
private:

};

#endif     //PRESIDENTIALPARDONFORM_H
