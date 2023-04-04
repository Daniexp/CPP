#include <WrongAnimal.hpp>

WrongAnimal::WrongAnimal()
{
//Const
	this->type = "";
	std::cout << "Default Constructor WrongAnimal." << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& tp)
{
	this->type = tp;
	std::cout << "Type Constructor WrongAnimal." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
//Copy Const
	std::cout << "Copy Constructor WrongAnimal." << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal()
{
//Dest
	std::cout << "Destructor WrongAnimal." << std::endl;
}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal& src)
{
	this->type = src.getType();
	return *this;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "The Wrong Animal has no sound." << std::endl;
}

void WrongAnimal::setType(const std::string& tp)
{
	this->type = tp;
}
