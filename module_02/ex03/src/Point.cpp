#include "Point.hpp"
 
Point::Point(): x(0), y(0)
{
}
Point::~Point()
{
}
Point::Point(const Point& src): x(src.getX()), y(src.getY())
{
}
Point::Point(const float& first, const float& second): x(first), y(second)
{
}
Point::Point(const Fixed& first, const Fixed& second): x(first), y(second)
{
}
Point& Point::operator = (Point& src)
{
	/*
	if (this != &src)
	{
		x = src.getX();
		y = src.getY();
	}
	return (*this);
*/
	return src;
}
/*
Fixed& Point::operator = (const Fixed& src) const
{
	width = src.getRawBits();
	return (this->width);
}
*/
Fixed Point::getX(void) const
{
	return (x);
}
Fixed Point::getY(void) const
{
	return (y);
}
