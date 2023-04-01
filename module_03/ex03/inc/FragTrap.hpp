#ifndef FRAGTRAP_H
#define FRAGTRAP_H
#include <ex02.hpp>
#include <ClapTrap.hpp>
class	FragTrap : public ClapTrap
{
	public:
	FragTrap();
	~FragTrap();
	FragTrap(const FragTrap& src);
	FragTrap(const std::string& name);
	FragTrap& operator = (const FragTrap& src);
	void	attack(std::string const& target);
	void	highFivesGuys(void);
	private:
};

#endif //FRAGTRAP_H


