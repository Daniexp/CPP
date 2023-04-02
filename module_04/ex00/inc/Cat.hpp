#ifndef CAT_H
#define CAT_H

#include <src.hpp>
class Cat
{
public:
    Cat();
    ~Cat();
   Cat(const Cat& src);
   Cat&    operator = (const Cat& src);
private:

};

#endif     //CAT_H
