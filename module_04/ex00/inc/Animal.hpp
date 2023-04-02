#ifndef ANIMAL_H
#define ANIMAL_H

#include <src.hpp>
class Animal
{
public:
    Animal();
    ~Animal();
   Animal(const Animal& src);
   Animal&    operator = (const Animal& src);
private:

};

#endif     //ANIMAL_H
