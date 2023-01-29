#include "Fixed.hpp"
 
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	width = 0;
}
Fixed::Fixed(const int nmb)
{
	std::cout << "Int constructor called" << std::endl;
	width = nmb << 8;
} 
Fixed::Fixed(const float nmb)
{
	std::cout << "Float constructor called" << std::endl;
	int units = roundf(nmb);
	float decimal = nmb - units;
	int decbits = (int)(decimal * (1 << 8));
	width = units * (1 << 8) + decbits;
}
Fixed::Fixed(const Fixed& src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}
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
	std::cout << "Destructor called" << std::endl;
}
float Fixed::toFloat(void) const
{
	int mask_dec = 0xff;	// 0xff = 11111111
	int unit, decimal;
	decimal = width & mask_dec;
	unit = width >> 8;
	float	res = (float) unit;
	if (decimal == 0)
		return (res);
	return (res + (float) decimal / (1 << 8));
}
int Fixed::toInt(void) const
{
	int mask_dec = 0xff;	// 0xff = 11111111
	int unit, decimal;
	decimal = width & mask_dec;
	unit = width >> 8;
	float	res = 0.0;
	if (decimal == 0)
		return (unit);
	res = (float) decimal / (1 << 8);
	res += unit;
	return ((int) res);
}
std::ostream& operator<< (std::ostream& os, const Fixed& f)
{
	return (os << f.toFloat());
}
