#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H
#include <ex03.hpp>
# include <ScavTrap.hpp>
# include <FragTrap.hpp>

class	DiamondTrap : virtual public FragTrap, virtual public ScavTrap
{
	public:
	DiamondTrap();
	~DiamondTrap();
	DiamondTrap(const DiamondTrap& src);
	DiamondTrap(const std::string& name);
	DiamondTrap& operator = (const DiamondTrap& src);
	void	whoAmI(void);
	void	attack(std::string const & target);
	private:
	std::string	Name;
};

#endif //DIAMONDTRAP_H


