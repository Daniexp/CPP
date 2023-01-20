#include <HumanB.hpp>
 
HumanB::HumanB(std::string nm)
{
//Const
	name = nm;
	weapon = new(Weapon);
}
HumanB::~HumanB()
{
//Dest
	delete (weapon);
}
void HumanB::setWeapon(Weapon& wp)
{
	weapon = &wp;
}
void HumanB::attack(void)
{
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
