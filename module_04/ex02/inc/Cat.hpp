#ifndef CAT_H
#define CAT_H

#include <iostream>
#include <string>
#include <Animal.hpp>
#include <Brain.hpp>
class Cat : public Animal
{
public:
	Cat();
	virtual ~Cat();
   Cat(const Cat& src);
   Cat& operator=(const Cat& src);
   virtual void makeSound() const;
   virtual std::string getIdea(int pos) const;
   virtual void setIdea(int pos,const std::string idea);
private:
	Brain* _brain;
};

#endif     //CAT_H
