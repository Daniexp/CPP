#include "Fixed.hpp"
 
Fixed::Fixed()
{
//Const
	width = 0;
}
Fixed::Fixed(const int& nmb)
{
	setRawBits(nmb);
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
	width = src.getRawBits();
	return *this;
}
void Fixed::setRawBits(int const src)
{
	width = src;
}
int Fixed::getBinary(void) const
{
	return (binaryPoint);
}
int Fixed::getRawBits(void) const
{
	return (width);
}
Fixed::~Fixed()
{
//Dest
}

