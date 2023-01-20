#ifndef HUMANA_H
#define HUMANA_H
# pragma once
# include <iostream>
# include <string>
# include <Weapon.hpp>
class	HumanA
{
	public:
	HumanA(std::string nm,Weapon& wp);
	~HumanA();
	void attack(void);
	private:
	Weapon&	weapon;
	std::string name;
};
#endif //HUMANA_H
