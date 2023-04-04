#include <Dog.hpp>

Dog::Dog() : Animal("Dog"), _brain(new Brain())
{
//Const
	std::cout << "Dog Default Constructor" << std::endl;
}

Dog::Dog(const Dog& src) : Animal(src), _brain(new Brain())
{
//Copy Const
	std::cout << "Dog Copy Constructor" << std::endl;
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
	Animal::operator=(src);
	for (int i = 0; i < 100; i++)
		this->_brain->setIdea(1, src._brain->getIdea(i));
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Guau guau guau..." << std::endl;
}
