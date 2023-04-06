#include <ICharacter.hpp>

/*
ICharacter::ICharacter()
{
//Const
	name = "";
	numMat = 0;
	for (int i=0; i < 4; i++)
		inventory[i] = nullptr;
}

ICharacter::ICharacter(const ICharacter& src)
{
//Copy Const
	*this = src;
	std::cout << "Copy Constructor ICharacter" << std::endl;
}
*/

ICharacter::~ICharacter()
{
//Dest
	std::cout << "Destructor ICharacter" << std::endl;
}

AMateria* ICharacter::getMateria(int idx)
{
	if (idx < 0)
		idx++;
	return nullptr;	
}

/*
ICharacter& ICharacter::operator = (const ICharacter& src)
{
	if (this != &src)
	{
		for (int i=0; i < 4; i++)
			inventory[i] = src.inventory[i]->clone();
		numMat = src.numMat;
	}
	return *this;
}
*/
