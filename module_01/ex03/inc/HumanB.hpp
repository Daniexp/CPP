#ifndef HUMANB_H
#define HUMANB_H
# include <iostream>
# include <string>
# include <Weapon.hpp>
class	HumanA
{
	public:
	HumanA(std::string nm);
	~HumanA();
	void setWeapon(const Weapon& wp);
	void attack(void);
	private:
	Weapon	weapon;
	std::string name;
};
#endif //HUMANB_H
