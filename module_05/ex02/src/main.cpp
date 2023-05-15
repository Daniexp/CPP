#include <iostream>
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <GradeTooLowException.hpp>
#include <GradeTooHighException.hpp>
#include <AForm.hpp>
#include <Bureaucrat.hpp>
#include <string>
#include <ShrubberyCreationForm.hpp>



int main(void)
{
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

    return 0;
}
