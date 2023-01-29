#ifndef FIXED_H
#define FIXED_H
#include <iostream>
#include <string>
class	Fixed
{
	public:
	Fixed();
	Fixed(const int& nmb);
	Fixed(const Fixed& src);
	~Fixed();
	Fixed& operator = (const Fixed& src);
	void	setRawBits(int const raw);
	int		getBinary( void ) const;
	int		getRawBits( void ) const;
	private:
	int	width;
	static const int binaryPoint = 8;

};

#endif //FIXED_H


