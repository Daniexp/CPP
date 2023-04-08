#include "ScavTrap.hpp"
 
ScavTrap::ScavTrap() : ClapTrap()//, hit_pts(100), energy_pts(50), attack_dmg(20), 
{
//Const
	set_hitpts(100);
	set_energypts(50);
	set_attackdmg(20);
	std::cout << "Default Constructor of ScavTrap." << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)//, hit_pts(100), energy_pts(50), attack_dmg(20), 
{
//Const
	set_hitpts(100);
	set_energypts(50);
	set_attackdmg(20);
	std::cout << "Name Constructor of ScavTrap." << std::endl;
}

ScavTrap::~ScavTrap()
{
//Dest
	std::cout << "Destructor of ScavTrap." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src)
{
	std::cout << "Copy Constructor of ScavTrap." << std::endl;	
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src)
{
	set_name(src.get_name());
	set_hitpts(src.get_hitpts());
	set_attackdmg(src.get_attackdmg());
	set_energypts(src.get_energypts());
	return *this;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "The ScavTrap " << this->get_name() << " is now in the Gate keeper mode." << std::endl;
}

void ScavTrap::attack(std::string const& target)
{
	if (target == "" || this->get_hitpts() == 0 || this->get_energypts() == 0)
		return ;
	std::cout << "ScavTrap " << this->get_name() << " attacks "  << target
		<< ", causing " << this->get_attackdmg() << " points of damage!" << std::endl;
		return ;
}
