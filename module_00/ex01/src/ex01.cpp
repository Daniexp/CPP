#include <ex01.hpp>
int main(void)
{
	std::cout << "The proyect was created sucessfully." << std::endl;
	Contact	ejemplo("Nombre", "Segundo nombre", "nickname", "número de telefono", "secreto mas oscuro");
	ejemplo.printData();
	PhoneBook agenda;
	agenda.addContact();
}
