#include <Ice.hpp>

Ice::Ice() : AMateria("ice")
{
//Const
}

Ice::Ice(const Ice& src) : AMateria(src)
{
//Copy Const
	//*this = src;
	std::cout << "Copy Constructor Ice" << std::endl;
}

Ice::~Ice()
{
//Des*/t
}

Ice& Ice::operator = (const Ice& src)
{
	AMateria::operator=(src);
	return *this;
}

AMateria* Ice::clone() const
{
	return new Ice();
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
