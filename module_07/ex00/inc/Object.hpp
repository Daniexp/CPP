#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <string>
class Object
{
public:
	Object();
	Object(int val);
	~Object();
   Object(const Object& src);
   Object& operator=(const Object& src);
   int operator<(const Object& src);
   int operator>(const Object& src);
private:
	int value;
};

#endif     //OBJECT_H
