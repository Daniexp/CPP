#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <GradeTooLowException.hpp>
#include <GradeTooHighException.hpp>
#include <AForm.hpp>
#include <Bureaucraft.hpp>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <fstream>

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm();
	~RobotomyRequestForm();
   RobotomyRequestForm(const RobotomyRequestForm& src);
	RobotomyRequestForm(const std::string& target);

   RobotomyRequestForm& operator=(const RobotomyRequestForm& src);
   virtual void doAction(const std::string& target) const;
private:

};

#endif     //ROBOTOMYREQUESTFORM_H
