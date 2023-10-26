#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <iostream>
#include <string>
struct Data
{
	int x;
	int y;
	int add;
	int sub;
	int div;
	int mul;
};

class Serializer
{
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
private:
	Serializer(void);
};

#endif     //SERIALIZER_H
