#include <iostream>
#include <Intern.hpp>
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <GradeTooLowException.hpp>
#include <GradeTooHighException.hpp>
#include <AForm.hpp>
#include <Bureaucrat.hpp>
#include <string>
#include <ShrubberyCreationForm.hpp>
#include <test.hpp>

void leaks(void)
{
	system("leaks -q ex03");
}

void 	createForms(AForm **f1, AForm **f2, AForm **f3)
{
	Intern inter;

	*f1 = inter.makeForm("shrubbery creation", "exampleTarget");
	*f2 = inter.makeForm("robotomy request", "exampleTarget");
	*f3 = inter.makeForm("presidential pardon", "exampleTarget");
}
void 	deleteForms(AForm *f1, AForm *f2, AForm *f3)
{
	delete f1;
	delete f2;
	delete f3;
}

int main(void)
{
	std::atexit(leaks);
	int	messageLength = 60;
	char	fillchar = '-';

	testBureaucrat(messageLength, fillchar);
	testShrubberyCreationForm(messageLength, fillchar);
	testRobotomyRequestForm(messageLength, fillchar);
	testPresidentialPardonForm(messageLength, fillchar);

	imprimirCentrado("", messageLength, fillchar);
	imprimirCentrado("INTERN TEST", messageLength, fillchar);
	imprimirCentrado("", messageLength, fillchar);

 	Bureaucrat bureaucrat("John Doe", 100);

	AForm *shrubberyForm;
	AForm *robotomyForm;
	AForm *pardonForm;

    	createForms(&shrubberyForm, &robotomyForm, &pardonForm);

	testIntern(shrubberyForm, messageLength, fillchar);
	testIntern(robotomyForm, messageLength, fillchar);
	testIntern(pardonForm, messageLength, fillchar);

	deleteForms(shrubberyForm, robotomyForm, pardonForm);
    return 0;
}
