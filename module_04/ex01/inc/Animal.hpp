#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
class Animal
{
public:
	Animal();
	virtual ~Animal();
   Animal(const Animal& src);
   Animal(const std::string tp);
   Animal& 		operator=(const Animal& src);
   virtual void	makeSound() const;
   std::string	getType() const;
   void			setType(const std::string& tp);
private:

protected:
   std::string type;
};

#endif     //ANIMAL_H
