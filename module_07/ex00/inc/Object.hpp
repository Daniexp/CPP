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
   bool operator<(const Object& src);
   bool operator>(const Object& src);
	bool operator==(const Object& src) const;
	int getValue();
private:
	int value;
};

#endif     //OBJECT_H
