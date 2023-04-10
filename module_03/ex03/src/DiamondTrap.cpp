#include "DiamondTrap.hpp"
 
DiamondTrap::DiamondTrap() : FragTrap("")//, FragTrap(), ScavTrap()
{
//Const
	std::cout << "Default Constructor DiamondTRap" << std::endl;
}
 
DiamondTrap::~DiamondTrap()
{
//Dest
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) : FragTrap(src)//, FragTrap(src), ScavTrap(src)
{
//Const
	std::cout << "Copy Constructor DiamondTRap" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : FragTrap(name + "_clap_name"), ScavTrap(name)
{
//Const
	std::cout << "Name Constructor DiamondTRap" << std::endl;
	set_hitpts(100);
	set_energypts(50);
	set_attackdmg(30);
	ClapTrap::set_name(name + "_clap_name");
	Name = name;
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

void DiamondTrap::attack(std::string const & target)
{
	ScavTrap::attack(target);
}
