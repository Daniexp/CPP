#ifndef DOG_H
#define DOG_H

#include <iostream>
#include <string>
#include <Animal.hpp>
class Dog : virtual public Animal
{
public:
	Dog();
	~Dog();
   Dog(const Dog& src);
   Dog& operator=(const Dog& src);
private:

};

#endif     //DOG_H
