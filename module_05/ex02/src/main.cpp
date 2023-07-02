#include <iostream>
#include <string>
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <GradeTooLowException.hpp>
#include <GradeTooHighException.hpp>
#include <AForm.hpp>
#include <Bureaucrat.hpp>
#include <ShrubberyCreationForm.hpp>
#include <test.hpp>



int main(void)
{
	int messageLength = 60;
	char fillchar = '-';

	testBureaucrat(messageLength, fillchar);

	testShrubberyCreationForm(messageLength, fillchar);

	testRobotomyRequestForm(messageLength, fillchar);

	testPresidentialPardonForm(messageLength, fillchar);

	return 0;
}
