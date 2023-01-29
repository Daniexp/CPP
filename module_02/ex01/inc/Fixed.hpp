#ifndef FIXED_H
#define FIXED_H
#include <iostream>
#include <string>
#include <cmath>
class	Fixed
{
	public:
	Fixed();
	Fixed(const Fixed& src);
	Fixed(const int nmb);
	Fixed(const float nmb);
	~Fixed();
	Fixed& operator=(const Fixed& src);
	void	setRawBits(int const raw);
	int		getBinary( void ) const;
	int		getRawBits( void ) const;
	float	toFloat( void ) const;
	int		toInt( void ) const;
	private:
	int	width;
	static const int binaryPoint = 8;

};
std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif //FIXED_H


