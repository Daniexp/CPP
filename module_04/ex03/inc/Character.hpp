#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <ICharacter.hpp>
class Character : public ICharacter
{
public:
	Character();
	virtual ~Character();
	Character(const std::string& Name);
   Character(const Character& src);
   Character& operator=(const Character& src);
	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
private:

};

#endif     //CHARACTER_H
