#include <iostream>
#include <Bureaucrat.hpp>
#include <string>

int main(void)
{
	std::cout << "The proyect was created sucessfully." << std::endl;
	Bureaucrat Pepe = Bureaucrat("Pepe", 150);
	std::cout << Pepe;
	Pepe.incrementGrade();
	std::cout << Pepe;

	return 0;
}
