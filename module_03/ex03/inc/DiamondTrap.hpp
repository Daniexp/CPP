#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H
#include <ex03.hpp>
# include <ScavTrap.hpp>
# include <FragTrap.hpp>

class	DiamondTrap : public FragTrap, public ScavTrap
{
	public:
	DiamondTrap();
	~DiamondTrap();
	DiamondTrap(const DiamondTrap& src);
	DiamondTrap(const std::string& name);
	DiamondTrap& operator = (const DiamondTrap& src);
	void	whoAmI(void);
	using ScavTrap::attack;
	private:
	std::string	Name;
};

#endif //DIAMONDTRAP_H


