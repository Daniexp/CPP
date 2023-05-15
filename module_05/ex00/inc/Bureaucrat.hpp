#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat
{
public:
   class GradeTooHighExcept : public std::exception
	{
		//Reimplementacion de what() en std::except
		virtual const char * what() const throw();
	};
   class GradeTooLowExcept : public std::exception
	{
		virtual const char * what() const throw();
	};

   Bureaucrat();
   Bureaucrat(const Bureaucrat& src);
   Bureaucrat(const std::string& _name, int _grade);
   ~Bureaucrat();
   Bureaucrat& operator=(const Bureaucrat& src);

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
std::ostream& operator << (std::ostream& os, const Bureaucrat& src);
#endif     //BUREAUCRAFT_H
