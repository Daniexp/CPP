#ifndef CAT_H
#define CAT_H

#include <iostream>
#include <string>
#include <Animal.hpp>
class Cat : public Animal
{
public:
	Cat();
	virtual ~Cat();
   Cat(const Cat& src);
   Cat& operator=(const Cat& src);
   virtual void makeSound() const;
private:

};

#endif     //CAT_H
