#ifndef ICHARACTER_H
#define ICHARACTER_H

#include <iostream>
#include <string>
#include <AMateria.hpp>

class AMateria;

class ICharacter
{
public:
	ICharacter();
	virtual ~ICharacter();
    ICharacter(const ICharacter& src);
    ICharacter& operator=(const ICharacter& src);
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
protected:
	std::string name;
	AMateria* inventory[4];
	int numMat;
};
#endif     //ICHARACTER_H
