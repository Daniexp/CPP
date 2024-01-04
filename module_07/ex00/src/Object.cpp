#include <Object.hpp>

Object::Object() : value(0)
{
//Const
}
Object::Object(int val) : value(val)
{
//Const
}


Object::Object(const Object& src)
{
//Copy Const
	*this = src;
}

Object::~Object()
{
//Dest
}

Object& Object::operator = (const Object& src)
{
	this->value = src.value;
	return *this;
}

int Object::operator < (const Object& src)
{
	return this->value < src.value;
}

int Object::operator > (const Object& src)
{
	return (this->value > src.value ? this->value : src.value);
}
