#include <AMateria.hpp>

AMateria::AMateria()
{
//Const
}

AMateria::AMateria(const AMateria& src)
{
//Copy Const
	*this = src;
}

AMateria::~AMateria()
{
//Dest
}

AMateria& AMateria::operator = (const AMateria& src)
{
	return *this;
}
