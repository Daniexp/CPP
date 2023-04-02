#include "DiamondTrap.hpp"
 
DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
//Const
	std::cout << "Default Constructor DiamondTRap" << std::endl;
}
 
DiamondTrap::~DiamondTrap()
{
//Dest
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) : ClapTrap(src), FragTrap(src), ScavTrap(src)
{
//Const
	std::cout << "Copy Constructor DiamondTRap" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
//Const
	std::cout << "Name Constructor DiamondTRap" << std::endl;
}

DiamondTrap& DiamondTrap::operator = (const DiamondTrap& src)
{
	set_name(src.get_name());
	set_hitpts(src.get_hitpts());
	set_attackdmg(src.get_attackdmg());
	set_energypts(src.get_energypts());
	return *this;
}

void DiamondTrap::whoAmI( void )
{
	std::cout << "I am " << Name << " and my ClapTrap name is " << ClapTrap::get_name() << std::endl; 
}
