#ifndef HUMANB_H
#define HUMANB_H
# pragma once
# include <iostream>
# include <string>
# include <Weapon.hpp>
class	HumanB
{
	public:
	HumanB(std::string nm);
	~HumanB();
	void setWeapon(Weapon& wp);
	void attack(void);
	private:
	Weapon*	weapon;
	std::string name;
};
#endif //HUMANB_H
