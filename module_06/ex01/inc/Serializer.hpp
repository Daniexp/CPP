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
	~Serializer(void);
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
	Serializer& operator = (const Serializer& src);
private:
	Serializer(void);
	Serializer(const Serializer& src);
	Data data;
};

#endif     //SERIALIZER_H
