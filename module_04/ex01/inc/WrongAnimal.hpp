#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>
#include <string>
class WrongAnimal
{
public:
	WrongAnimal();
	virtual ~WrongAnimal();
   WrongAnimal(const WrongAnimal& src);
   WrongAnimal(const std::string& src);
   WrongAnimal& operator=(const WrongAnimal& src);
   std::string getType() const;
   void setType(const std::string& tp);
   void makeSound() const;
private:
	std::string type;
};

#endif     //WRONGANIMAL_H
