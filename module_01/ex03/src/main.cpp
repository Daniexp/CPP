#include <Weapon.hpp>
#include <HumanA.hpp>
#include <HumanB.hpp>
int main(void)
{
	std::string name = "Knife";
	std::string hmName = "Pepe";
	Weapon	ej=Weapon(name);
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
	club = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.setWeapon(club);
	jim.attack();
	club.setType("some other type of club");
	jim.attack();
}
