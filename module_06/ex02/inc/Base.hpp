#ifndef BASE_H
#define BASE_H
#define TOTAL_DERIVED_CLASSES 3

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

class Base
{
public:
	virtual ~Base();
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif     //BASE_H
