#include <Weapon.hpp>
#include <HumanA.hpp>
int main(void)
{
	std::cout << "The proyect was created sucessfully." << std::endl;
	std::string name = "Knife";
	std::string hmName = "Pepe";
	Weapon	ej=Weapon(name);
//	std::string& ref=name;
	std::cout << ej.getType() << std::endl;
	name = "Spear";
	ej.setType(name);
	std::cout << ej.getType() << std::endl;
	HumanA	hum1=HumanA(hmName, ej);
	hum1.attack();
	std::cout << "---------------------" << std::endl;

Weapon club = Weapon("crude spiked club");
HumanA bob("Bob", club);
bob.attack();
club.setType("some other type of club");
bob.attack();
}
