#include <Animal.hpp>

Animal::Animal()
{
//Const
	this->type = "";
	std::cout << "Animal Deafault Constructor." << std::endl;
}

Animal::Animal(const Animal& src)
{
//Copy Const
	*this = src;
	std::cout << "Animal Copy Constructor." << std::endl;
}

Animal::Animal(const std::string tp) : type(tp)
{
	std::cout << "Animal Type Constructor." << std::endl;
}

Animal::~Animal()
{
//Dest
	std::cout << "Animal Destructor." << std::endl;
}

Animal& Animal::operator = (const Animal& src)
{
	this->type = src.type;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "The Animal makes her sound ... " << std::endl;
}

std::string Animal::getType( void ) const
{
	return this->type;
}
void Animal::setType(const std::string& tp)
{
	this->type = tp;
}
