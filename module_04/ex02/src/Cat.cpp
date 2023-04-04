#include <Cat.hpp>

Cat::Cat() : _brain(new Brain())
{
//Const
	//this->type = "Cat";
	setType("Cat");
	std::cout << "Cat Constructor Default" << std::endl;
}

Cat::Cat(const Cat& src) : _brain(new Brain())
{
//Copy Const
	*this = src;
	setType(src.getType());
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
		this->setType(src.getType());
		_brain = src._brain;
	}
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Miau miau miau..." << std::endl;
}

std::string Cat::getIdea(int pos) const
{
	return this->_brain->getIdea(pos);
}

void Cat::setIdea(int pos, const std::string idea)
{
	this->_brain->setIdea(pos, idea);
}
