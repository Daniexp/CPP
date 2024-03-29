#ifndef SCAVTRAP_H
#define SCAVTRAP_H
#include <ex03.hpp>
#include <ClapTrap.hpp>
class	ScavTrap : virtual public ClapTrap
{
	public:
	ScavTrap();
	~ScavTrap();
	ScavTrap(const ScavTrap& src);
	ScavTrap(const std::string& name);
	ScavTrap& operator=(const ScavTrap& src);
	void attack(std::string const& target);
	void guardGate(void);
};

#endif //SCAVTRAP_H


