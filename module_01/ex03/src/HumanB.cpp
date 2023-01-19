#include <HumanB.hpp>
 
HumanB::HumanB(std::string nm)
{
//Const
	name = nm;
	weapon;
}
HumanA::~HumanA()
{
//Dest
	delete (wp);
}
void HumanB::setWeapon(const Weapon& wp)
{
	weapon = new(Weapon);
	weapon = wp;
}
void HumanA::attack(void)
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
