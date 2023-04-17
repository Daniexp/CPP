#include <iostream>
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
