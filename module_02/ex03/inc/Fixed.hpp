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
	//operadores de comparación
	bool	operator > (const Fixed& src) const;
	bool	operator < (const Fixed& src) const;
	bool	operator >= (const Fixed& src) const;
	bool	operator <= (const Fixed& src) const;
	bool	operator == (const Fixed& src) const;
	bool	operator != (const Fixed& src) const;
	//operadores aritméticos
	Fixed	operator + (const Fixed& src) const;
	Fixed	operator - (const Fixed& src) const;
	Fixed	operator * (const Fixed& src) const;
	Fixed	operator / (const Fixed& src) const;
	//operadores de preinc, post, pred y post decrem
	//pre
	Fixed&	operator ++(void);
	Fixed&	operator --(void);
	//pos
	Fixed	operator ++(int val);
	Fixed	operator --(int val);
	// Min and Max
	static const Fixed& min(const Fixed& first, const Fixed& second);
	static const Fixed& max(const Fixed& first, const Fixed& second);
	private:
	int	width;
	static const int binaryPoint = 8;

};
std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif //FIXED_H
