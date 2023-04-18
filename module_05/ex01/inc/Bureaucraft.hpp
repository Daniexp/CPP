#ifndef BUREAUCRAFT_H
#define BUREAUCRAFT_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <GradeTooHighException.hpp>
#include <GradeTooLowException.hpp>

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
  //void setName(const std::string& _name);
  //void setGrade(int _grade);
private:
	const std::string name;
	int grade;
};
std::ostream& operator << (std::ostream& os, const Bureaucraft& src);
#endif     //BUREAUCRAFT_H
