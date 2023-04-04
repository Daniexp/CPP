#include <WrongCat.hpp>

WrongCat::WrongCat() : WrongAnimal("Cat")
{
//Const
	std::cout << "Default Constructor WrongCat." << std::endl;
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal(src)
{
//Copy Const
	std::cout << "Copy Constructor WrongCat." << std::endl;
	*this = src;
}

WrongCat::~WrongCat()
{
//Dest
	std::cout << "Destructor WrongCat." << std::endl;
}

WrongCat& WrongCat::operator = (const WrongCat& src)
{
	setType(src.getType());
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "Uaim uaim uaim..." << std::endl;
}
