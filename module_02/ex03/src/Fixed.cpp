#include "Fixed.hpp"
 
Fixed::Fixed()
{
//Const
//	std::cout << "Default constructor called" << std::endl;
	width = 0;
}
Fixed::Fixed(const int nmb)
{
	/*
	int sign = 0;
	if (nmb < 0 )
		sign = 1;
	int cmp2 = nmb;
	cmp2 = (~cmp2) + 1;
	cmp2 <<= 8;
	int pos = 1 << 31;
	int neg = ~(1 << 31);
	if (!sign)
		cmp2 = cmp2 | pos;
	else
		cmp2 = cmp2 & neg;	
	width = cmp2;
	*/
//	int decimal = 8 >> (32 - 8);
	width = nmb << 8;
} 
Fixed::Fixed(const float nmb)
{
	//comprobar si el decimal es válido 
	//guardar parte entera y parte decimal
	//manipular parte decimal para que ocupe 8 bits.
	//añadir bin de parte entera al bin de la parte decimal
//	std::cout << "El numero es " << nmb << std::endl;
//	int units = (int)(nmb + 0.5);
	//int units = floor(nmb);
	int units = roundf(nmb);
	float decimal = nmb - units;
	int decbits = (int)(decimal * (1 << 8));
	width = units * (1 << 8) + decbits;
}
Fixed::Fixed(const Fixed& src)
{
//	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}
/*
Fixed::Fixed(const Fixed* src)
{}
*/
Fixed& Fixed::operator = (const Fixed& src)
{
//	std::cout << "Assignation operator called" << std::endl;
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
//	std::cout << "Destructor called" << std::endl;
}
std::ostream& operator<< (std::ostream& os, const Fixed& f)
{
	return (os << f.toFloat());
//	return (os);
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
	//res = (float) decimal / (1 << 8);
	return (res + (float) decimal / (1 << 8));
}
int Fixed::toInt(void) const
{
	//int comp1 = ~(width) + 1;
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
bool	Fixed::operator>(const Fixed& src) const
{
	return (this->toFloat() > src.toFloat());
}
bool	Fixed::operator<(const Fixed& src) const
{
	return (this->toFloat() < src.toFloat());
}
bool	Fixed::operator>=(const Fixed& src) const
{
	return (this->toFloat() >= src.toFloat());
}
bool	Fixed::operator==(const Fixed& src) const
{
	return (this->toFloat() == src.toFloat());
}
bool	Fixed::operator!=(const Fixed& src) const
{
	return (this->toFloat() != src.toFloat());
}
Fixed	Fixed::operator+(const Fixed& src) const
{
	return (Fixed(this->toFloat() + src.toFloat()));
}
Fixed	Fixed::operator-(const Fixed& src) const
{
	return (Fixed(this->toFloat() - src.toFloat()));
}
Fixed	Fixed::operator*(const Fixed& src) const
{
	return (Fixed(this->toFloat() * src.toFloat()));
}
Fixed	Fixed::operator/(const Fixed& src) const
{
	return (Fixed(this->toFloat() / src.toFloat()));
}
Fixed&	Fixed::operator++(void)
{
	width += 1;
	return (*this);
}

Fixed&	Fixed::operator--(void)
{
	width -= 1;
	return (*this);
}
Fixed	Fixed::operator++(int val)
{
	Fixed tmp(*this);
	width += val;
	return (tmp);
}
Fixed	Fixed::operator--(int val)
{
	Fixed tmp(*this);
	width -= val;
	return (tmp);
}
const	Fixed& Fixed::min(const Fixed& first, const Fixed& second)
{
	return (first < second) ? first : second;
}
const	Fixed& Fixed::max(const Fixed& first, const Fixed& second)
{
	return (first > second) ? first : second;
}
