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
//	testAForm(messageLength, fillchar);
// Crear un burócrata
    Bureaucrat bureaucrat("John Doe", 100);

    // Crear instancias de los formularios
    ShrubberyCreationForm shrubberyForm("home");
    RobotomyRequestForm robotomyForm("target");
    PresidentialPardonForm pardonForm("target");

    try {
        // Firmar y ejecutar el formulario ShrubberyCreationForm
        bureaucrat.signForm(shrubberyForm);
        bureaucrat.executeForm(shrubberyForm);

        // Firmar y ejecutar el formulario RobotomyRequestForm
        bureaucrat.signForm(robotomyForm);
        bureaucrat.executeForm(robotomyForm);

        // Firmar y ejecutar el formulario PresidentialPardonForm
        bureaucrat.signForm(pardonForm);
        bureaucrat.executeForm(pardonForm);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
try {
        // Crear un burócrata
        Bureaucrat bureaucrat("Big Boss", 1);

        // Crear instancias de los formularios
        ShrubberyCreationForm shrubberyForm("home");
        RobotomyRequestForm robotomyForm("target");
        PresidentialPardonForm pardonForm("target");

        // Firmar y ejecutar el formulario ShrubberyCreationForm
        bureaucrat.signForm(shrubberyForm);
        bureaucrat.executeForm(shrubberyForm);

        // Intentar ejecutar el formulario RobotomyRequestForm sin firmarlo primero
        bureaucrat.executeForm(robotomyForm);

        // Firmar nuevamente el formulario ShrubberyCreationForm (intento de firma duplicada)
        bureaucrat.signForm(shrubberyForm);

        // Firmar y ejecutar el formulario RobotomyRequestForm
        bureaucrat.signForm(robotomyForm);
        bureaucrat.executeForm(robotomyForm);

        // Intentar ejecutar el formulario PresidentialPardonForm sin firmarlo primero
        bureaucrat.executeForm(pardonForm);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}
