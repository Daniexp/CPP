#ifndef DOG_H
#define DOG_H

#include <src.hpp>
class Dog
{
public:
    Dog();
    ~Dog();
   Dog(const Dog& src);
   Dog&    operator = (const Dog& src);
private:

};

#endif     //DOG_H
