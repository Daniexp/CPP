#include <HumanA.hpp>
 
HumanA::HumanA(std::string nm, Weapon& wp) : weapon(wp)
{
//Const
//	this->weapon = wp;
	name = nm;
}
HumanA::~HumanA()
{
//Dest
}
void HumanA::attack(void)
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
