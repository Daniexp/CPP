#include <AMateria.hpp>


AMateria::AMateria()
{
	std::cout << "Default Constructor AMateria" << std::endl;
	type = "";
}

AMateria::AMateria(const AMateria& src)
{
//Copy Const
	*this = src;
	std::cout << "AMateria Copy Constructor";
}

AMateria::AMateria(std::string const & type)
{
	this->type = type;
	std::cout << "Type Constructor AMateria" << std::endl;
}
AMateria::~AMateria()
{
//Dest
	std::cout << "Destructor AMateria" << std::endl;
}
AMateria& AMateria::operator = (const AMateria& src)
{
	if (this != &src)
		type = src.type;
	return *this;
}

std::string const & AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* Nothing happened to " << target.getName() << std::endl;
}

std::ostream& operator << (std::ostream& os, const AMateria& A)
{
	os << "I'm type -> " << A.getType() << std::endl;
	return os;
}
