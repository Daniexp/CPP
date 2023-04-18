#include <iostream>
#include <GradeTooLowException.hpp>
#include <GradeTooHighException.hpp>
#include <Form.hpp>
#include <Bureaucraft.hpp>
#include <string>

int main(void)
{
	std::cout << "The proyect was created sucessfully." << std::endl;
	Bureaucraft Pepe = Bureaucraft("Pepe", 150);
	std::cout << Pepe;
	Pepe.incrementGrade();
	std::cout << Pepe;

	return 0;
}
