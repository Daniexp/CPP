#include <Animal.hpp>

Animal::Animal()
{
//Const
	this->type = "";
}

Animal::Animal(const Animal& src)
{
//Copy Const
	*this = src;
}

Animal::~Animal()
{
//Dest
}

Animal& Animal::operator = (const Animal& src)
{
	this->type = src.type;
	return *this;
}

void Animal::makeSound()
{
	std::cout << "The Animal makes her sound ... " << std::endl;
}
