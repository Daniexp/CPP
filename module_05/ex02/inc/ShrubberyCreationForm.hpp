#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <GradeTooHighException.hpp>
#include <GradeTooLowException.hpp>
#include <AForm.hpp>
#include <Bureaucraft.hpp>
#include <fstream>
class ShrubberyCreationForm : public AForm
{
public:
//	ShrubberyCreationForm();
	~ShrubberyCreationForm();
   ShrubberyCreationForm(const ShrubberyCreationForm& src);
	ShrubberyCreationForm(const std::string& target);

   ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);

   //virtual void execute(Bureaucraft const & executor) const;
   virtual void doAction(const std::string& target) const; 
   std::string buildTree(int h, int node, char left, char right);

private:

};

#endif     //SHRUBBERYCREATIONFORM_H
