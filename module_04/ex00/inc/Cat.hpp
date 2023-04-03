#ifndef CAT_H
#define CAT_H

#include <iostream>
#include <string>
#include <Animal.hpp>
class Cat : virtual public Animal
{
public:
	Cat();
	~Cat();
   Cat(const Cat& src);
   Cat& operator=(const Cat& src);
private:

};

#endif     //CAT_H
