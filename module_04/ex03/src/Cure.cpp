#include <Cure.hpp>

Cure::Cure() : AMateria("cure")
{
//Const
	std::cout << "Default Constructor Cure" << std::endl;
}

Cure::Cure(const Cure& src)
{
//Copy Const
	std::cout << "Copy Constructor Cure" << std::endl;
	*this = src;
}

Cure::~Cure()
{
//Dest
	std::cout << "Destructor Cure" << std::endl;
}

Cure& Cure::operator = (const Cure& src)
{
	AMateria::operator=(src);
	return *this;
}

AMateria* Cure::clone() const
{
	return new Cure();
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;	
}
