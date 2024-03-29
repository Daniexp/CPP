#include <Dog.hpp>

Dog::Dog() : Animal("Dog")
{
//Const
	std::cout << "Dog Default Constructor" << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src)
{
//Copy Const
	*this = src;
	std::cout << "Dog Copy Constructor" << std::endl;
}

Dog::~Dog()
{
//Dest
	std::cout << "Dog Destructor" << std::endl;
}

Dog& Dog::operator = (const Dog& src)
{
	//this->type = src.type;
	setType(src.getType());
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Guau guau guau..." << std::endl;
}
