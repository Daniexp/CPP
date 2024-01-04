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

bool Object::operator < (const Object& src)
{
	return this->value < src.value;
}

bool Object::operator > (const Object& src)
{
	return this->value > src.value;
}

bool Object::operator == (const Object& src) const
{
	return this->value == src.value;
}

int Object::getValue()
{
	return this->value;
}



