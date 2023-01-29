#include "Fixed.hpp"
 
Fixed::Fixed()
{
	width = 0;
}
Fixed::Fixed(const int nmb)
{
	width = nmb << 8;
} 
Fixed::Fixed(const float nmb)
{
	int units = roundf(nmb);
	float decimal = nmb - units;
	int decbits = (int)(decimal * (1 << 8));
	width = units * (1 << 8) + decbits;
}
Fixed::Fixed(const Fixed& src)
{
	*this = src;
}
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
}
std::ostream& operator<< (std::ostream& os, const Fixed& f)
{
	return (os << f.toFloat());
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
	if (!val)
		width += 1;
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
