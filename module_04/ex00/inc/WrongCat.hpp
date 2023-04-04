#ifndef WRONGCAT_H
#define WRONGCAT_H

#include <iostream>
#include <string>
#include <WrongAnimal.hpp>
class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	virtual ~WrongCat();
   WrongCat(const WrongCat& src);
   WrongCat& operator=(const WrongCat& src);
   void makeSound() const;
private:

};

#endif     //WRONGCAT_H
