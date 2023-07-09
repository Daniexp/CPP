#ifndef INTERN_H
#define INTERN_H

#include <iostream>
#include <string>
#include <AForm.hpp>
#include <PresidentialPardonForm.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <map>
class Intern
{
public:
	Intern();
	~Intern();
   Intern(const Intern& src);
   Intern& operator=(const Intern& src);
	AForm* makeForm(const std::string& name, const std::string& target);
private:
	std::string formName[3];
};

#endif     //INTERN_H
