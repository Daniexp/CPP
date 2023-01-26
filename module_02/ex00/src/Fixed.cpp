#include "Fixed.hpp"
 
Fixed::Fixed()
{
//Const
	std::cout << "Default constructor called" << std::endl;
	width = 0;
}
Fixed::Fixed(const int& nmb)
{
	setRawBits(nmb);
} 
Fixed::Fixed(const Fixed& src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}
/*
Fixed::Fixed(const Fixed* src)
{}
*/
Fixed& Fixed::operator = (const Fixed& src)
{
	std::cout << "Assignation operator called" << std::endl;
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
	std::cout << "getRawBits member function called" << std::endl;
	return (width);
}
Fixed::~Fixed()
{
//Dest
	std::cout << "Destructor called" << std::endl;
}

