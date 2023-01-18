#include <Weapon.hpp>
int main(void)
{
	std::cout << "The proyect was created sucessfully." << std::endl;
	std::string name = "Knife";
	Weapon	ej=Weapon(name);
//	std::string& ref=name;
	std::cout << ej.getType() << std::endl;
	name = "Spear";
	ej.setType(name);
	std::cout << ej.getType() << std::endl;

}
