#include "Fixed.hpp"
 
Fixed::Fixed()
{
//Const
	std::cout << "Default constructor called" << std::endl;
	width = 0;
}
Fixed::Fixed(const int nmb)
{
//	setRawBits(nmb);
//	std::cout << "PASAPORAQUI" << std::endl;
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
	//cmp2 >>= nmb;
	//cmp2 = (~cmp2) + 1;
	//cmp2 >>= 8;
	//	std::cout << "The int is bigger than we can safe in the class Fixed<32,8>" << std::endl;
	width = cmp2;
} 
Fixed::Fixed(const float nmb)
{
	//comprobar si el decimal es válido 
	//guardar parte entera y parte decimal
	//manipular parte decimal para que ocupe 8 bits.
	//añadir bin de parte entera al bin de la parte decimal
	std::cout << "El numero es " << nmb << std::endl;
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
float Fixed::operator << (const Fixed& nmb)
{
	return (nmb.toFloat());
}
float Fixed::toFloat(void) const
{
	return (0.0);
}
int Fixed::toInt(void) const
{
	return (0);
}
