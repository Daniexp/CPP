#include <Character.hpp>


Character::Character()
{
//Copy Const
	std::cout << "Copy Constructor Character" << std::endl;
	name = "";
	numMat = 0;
	for (int i=0; i < 4; i++)
		inventory[i] = nullptr;
}

Character::Character(const Character& src)
{
	*this = src;
}

Character::~Character()
{
//Dest
	std::cout << "Destructor Character" << std::endl; 
	for (int i=0; i < numMat; i++)
		delete inventory[i];
}

Character& Character::operator = (const Character& src)
{
	if (this != &src)
	{
		numMat = src.numMat;
		for (int i=0; i < numMat; i++)
		inventory[i] = src.inventory[i]->clone();
	}
	return *this;
}

Character::Character(const std::string& Name)
{
	this->name = Name;
	numMat = 0;
	for (int i=0; i < 4 ; i++)
		inventory[i] = nullptr;
}

std::string const& Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	if (numMat < 4 && m != nullptr)
		inventory[numMat++] = m;
}

void Character::unequip(int idx)
{
	if (idx < numMat && idx > -1 && idx < 4)
		inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < numMat && inventory[idx] != nullptr)
			inventory[idx]->use(target);
}

AMateria* Character::getMateria(int idx)
{
	if (idx >= 0 && idx < numMat)
		return inventory[idx];
	return nullptr;
}
