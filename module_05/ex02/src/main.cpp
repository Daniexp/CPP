#include <iostream>
#include <GradeTooLowException.hpp>
#include <GradeTooHighException.hpp>
#include <AForm.hpp>
#include <Bureaucraft.hpp>
#include <string>
#include <ShrubberyCreationForm.hpp>



int main(void)
{
	// Creamos un objeto de la clase Bureaucrat con un grade de 1
    Bureaucraft bureaucrat("John Doe", 1);

    // Creamos un objeto de la clase ShrubberyCreationForm con un target de "example"
    ShrubberyCreationForm form("example");

    // El burócrata intenta firmar la forma
    try {
        bureaucrat.signForm(form);
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // El burócrata intenta ejecutar la forma
    try {
        bureaucrat.executeForm(form);
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // La forma ejecuta su acción (creación del archivo con árboles en ASCII)
    form.doAction("ejemplo");

    return 0;
}
