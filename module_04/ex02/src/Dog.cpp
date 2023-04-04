#include <Dog.hpp>

Dog::Dog() : _brain(new Brain())
{
//Const
	std::cout << "Dog Default Constructor" << std::endl;
	setType("Dog");
}

Dog::Dog(const Dog& src) : _brain(new Brain())
{
//Copy Const
	std::cout << "Dog Copy Constructor" << std::endl;
	setType(src.getType());
	for (int i=0; i < 100; i++)
		this->_brain->setIdea(i, src._brain->getIdea(i));
}

Dog::~Dog()
{
//Dest
	std::cout << "Dog Destructor" << std::endl;
	delete(_brain);
}

Dog& Dog::operator = (const Dog& src)
{
	//this->type = src.type;
	if (this == &src)
		return *this;
	setType(src.getType());
	for (int i = 0; i < 100; i++)
		this->_brain->setIdea(1, src._brain->getIdea(i));
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Guau guau guau..." << std::endl;
}

std::string Dog::getIdea(int pos) const
{
	return this->_brain->getIdea(pos);
}

void Dog::setIdea(int pos, const std::string idea)
{
	this->_brain->setIdea(pos, idea);
}
