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
//	Fixed(const Fixed* src);
	~Fixed();
	Fixed& operator = (const Fixed& src);
	void		setWidth(const int& src);
	int	getBinary( void ) const;
	int	getWidth( void ) const;
	private:
	int	width;
	static const int binaryPoint = 8;

};

#endif //FIXED_H


