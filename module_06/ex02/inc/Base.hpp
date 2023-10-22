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

class A : public Base
{};
class B : public Base
{};
class C : public Base
{};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

std::string outputs[] = {"A", "B", "C", "ERROR: invalid argument"};
#endif     //BASE_H
