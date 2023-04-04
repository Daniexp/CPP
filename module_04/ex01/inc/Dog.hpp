#ifndef DOG_H
#define DOG_H

#include <iostream>
#include <string>
#include <Animal.hpp>
#include <Brain.hpp>
class Dog : public Animal
{
public:
	Dog();
	virtual ~Dog();
   Dog(const Dog& src);
   Dog& operator=(const Dog& src);
   virtual void	makeSound() const;
private:
	Brain* _brain;
};

#endif     //DOG_H
