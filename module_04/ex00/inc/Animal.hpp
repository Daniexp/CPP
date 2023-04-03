#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
class Animal
{
public:
	Animal();
	~Animal();
   Animal(const Animal& src);
   Animal& operator=(const Animal& src);
   void makeSound();
private:

protected:
   std::string type;
};

#endif     //ANIMAL_H
