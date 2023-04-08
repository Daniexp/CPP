#include "FragTrap.hpp"
 
FragTrap::FragTrap() : ClapTrap()
{
//Const
	set_hitpts(100);
	set_energypts(100);
	set_attackdmg(30);
	std::cout << "Default Constructor of FragTrap." << std::endl;
}
 
FragTrap::~FragTrap()
{
//Dest
	std::cout << "Destructor of FragTrap." << std::endl;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src)
{
	std::cout << "Copy Constructor of FragTrap" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "Name Constructor of FragTrap." << std::endl;
	set_hitpts(100);
	set_energypts(100);
	set_attackdmg(30);
}
FragTrap& FragTrap::operator = (const FragTrap& src)
{
	set_name(src.get_name());
	set_hitpts(src.get_hitpts());
	set_energypts(src.get_energypts());
	set_attackdmg(src.get_attackdmg());
	return *this;
}

void	FragTrap::attack(std::string const& target)
{
 if (target == "" || this->get_hitpts() == 0 || this->get_energypts() == 0)
 	return ;
	set_attackdmg(get_attackdmg());
 	std::cout << "FragTrap " << this->get_name() << " attacks "  << target << ", causing " << this->get_attackdmg() << " points of damage!" << std::endl;
	return ;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "-" << get_name() << ": Let's high fives guys !!!" << std::endl;
}
