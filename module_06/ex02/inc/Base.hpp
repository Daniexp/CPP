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
	Base* generate(void);
};

class A : public Base
{};
class B : public Base
{};
class C : public Base
{};

#endif     //BASE_H
