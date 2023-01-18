#include "Weapon.hpp"
 
Weapon::Weapon()
{
//Const
}
Weapon::Weapon(const std::string& value)
{
	type = value;
}	
 
Weapon::~Weapon()
{
//Dest
	std::cout << "My " << type << " crash into a million of pieces..." << std::endl;
}
const std::string&	Weapon::getType(void)
{
	return (type);
}
void	Weapon::setType(const std::string& value)
{
	type = value;
}

