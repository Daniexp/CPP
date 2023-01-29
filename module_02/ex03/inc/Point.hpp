#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <string>
#include <Fixed.hpp>
class	Point
{
	public:
	Point();
	~Point();
	Point(const Point& src);
	Point(const float& first, const float& second);
	Point(const Fixed& first, const Fixed& second);
	Point& operator = (Point& src);
	/**********************************/
	Fixed getX( void ) const;
	Fixed getY( void ) const;
	private:
	Fixed const x;
	Fixed const y;
};
bool bsp( Point const a, Point const b, Point const c, Point const point);
#endif //POINT_H


