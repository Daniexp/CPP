#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <string>
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
