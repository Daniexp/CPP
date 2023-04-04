#include <Cat.hpp>

Cat::Cat() : Animal("Cat"), _brain(new Brain())
{
//Const
	//this->type = "Cat";
	std::cout << "Cat Constructor Default" << std::endl;
}

Cat::Cat(const Cat& src) : Animal(src), _brain(new Brain())
{
//Copy Const
	*this = src;
	std::cout << "Cat Copy Constructor" << std::endl;
	_brain = src._brain;
}

Cat::~Cat()
{
//Dest
	std::cout << "Cat Destructor" << std::endl;
	delete _brain;
}

Cat& Cat::operator = (const Cat& src)
{
	if (this != & src)
	{
		Animal::operator=(src);
		_brain = src._brain;
	}
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Miau miau miau..." << std::endl;
}
