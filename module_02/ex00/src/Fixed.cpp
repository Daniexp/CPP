#include "Fixed.hpp"
 
Fixed::Fixed()
{
//Const
	width = 0;
}
Fixed::Fixed(const int& nmb)
{
	setWidth(nmb);
} 
Fixed::Fixed(const Fixed& src)
{
	*this = src;
}
/*
Fixed::Fixed(const Fixed* src)
{}
*/
Fixed& Fixed::operator = (const Fixed& src)
{
	width = src.getWidth();
	return *this;
}
void Fixed::setWidth(const int& src)
{
	width = src;
}
int Fixed::getBinary(void) const
{
	return (binaryPoint);
}
int Fixed::getWidth(void) const
{
	return (width);
}
Fixed::~Fixed()
{
//Dest
}

