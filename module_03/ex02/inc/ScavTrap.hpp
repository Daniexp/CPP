#ifndef SCAVTRAP_H
#define SCAVTRAP_H
#include <ex02.hpp>
#include <ClapTrap.hpp>
class	ScavTrap : public ClapTrap
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


