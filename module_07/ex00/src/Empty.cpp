#include <Empty.hpp>

Empty::Empty()
{
//Const
	this->value = 0;
}

Empty::Empty(const Empty& src)
{
//Copy Const
	*this = src;
}

Empty::~Empty()
{
//Dest
}

Empty& Empty::operator=(const Empty& src)
{
	this->value = src.value;
	return *this;
}

int Empty::getValue()
{
	return this->value;
}
