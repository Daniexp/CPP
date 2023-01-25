#ifndef WEAPON_H
#define WEAPON_H
#pragma once
#include <iostream>
#include <string>
class	Weapon
{
	public:
	Weapon();
	Weapon(const std::string& value);
	~Weapon();
	const std::string& getType(void) const;
	void	setType(const std::string& value);
	private:
	std::string	type;
};

#endif //WEAPON_H


