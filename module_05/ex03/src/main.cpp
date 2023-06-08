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
// Crear un burócrata
	std::atexit(leaks);
    Bureaucrat bureaucrat("John Doe", 100);
	AForm *shrubberyForm;
	AForm *robotomyForm;
	AForm *pardonForm;

    // Crear instancias de los formularios
    createForms(&shrubberyForm, &robotomyForm, &pardonForm);
    try {
        // Firmar y ejecutar el formulario ShrubberyCreationForm
        bureaucrat.signForm(*shrubberyForm);
        bureaucrat.executeForm(*shrubberyForm);

        // Firmar y ejecutar el formulario RobotomyRequestForm
        bureaucrat.signForm(*robotomyForm);
        bureaucrat.executeForm(*robotomyForm);

        // Firmar y ejecutar el formulario PresidentialPardonForm
        bureaucrat.signForm(*pardonForm);
        bureaucrat.executeForm(*pardonForm);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
	deleteForms(shrubberyForm, robotomyForm, pardonForm);
    	createForms(&shrubberyForm, &robotomyForm, &pardonForm);
try {
        // Crear un burócrata
        Bureaucrat bureaucrat("Big Boss", 1);

        // Crear instancias de los formularios

        // Firmar y ejecutar el formulario ShrubberyCreationForm
        bureaucrat.signForm(*shrubberyForm);
        bureaucrat.executeForm(*shrubberyForm);

        // Intentar ejecutar el formulario RobotomyRequestForm sin firmarlo primero
        bureaucrat.executeForm(*robotomyForm);

        // Firmar nuevamente el formulario ShrubberyCreationForm (intento de firma duplicada)
        bureaucrat.signForm(*shrubberyForm);

        // Firmar y ejecutar el formulario RobotomyRequestForm
        bureaucrat.signForm(*robotomyForm);
        bureaucrat.executeForm(*robotomyForm);

        // Intentar ejecutar el formulario PresidentialPardonForm sin firmarlo primero
        bureaucrat.executeForm(*pardonForm);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
	deleteForms(shrubberyForm, robotomyForm, pardonForm);
    return 0;
}
