#include "ScavTrap.hpp"
 
ScavTrap::ScavTrap() : ClapTrap()//, hit_pts(100), energy_pts(50), attack_dmg(20), 
{
//Const

}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)//, hit_pts(100), energy_pts(50), attack_dmg(20), 
{
//Const
}

ScavTrap::~ScavTrap()
{
//Dest
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src)
{
}

ScavTrap& operator=(const ScavTrap& src)
{
	if (this == & src)
		return *this;
	ClapTrap::operator=(src);

	return *this;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "The ScavTrap " << this->get_name() << " is now in the Gate keeper mode.";
}
