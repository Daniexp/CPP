#include <Cat.hpp>

Cat::Cat() : Animal("Cat")
{
//Const
	//this->type = "Cat";
	std::cout << "Cat Constructor Default" << std::endl;
}

Cat::Cat(const Cat& src) : Animal(src)
{
//Copy Const
	*this = src;
	std::cout << "Cat Copy Constructor" << std::endl;
}

Cat::~Cat()
{
//Dest
	std::cout << "Cat Destructor" << std::endl;
}

Cat& Cat::operator = (const Cat& src)
{
	setType(src.getType());
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Miau miau miau..." << std::endl;
}
