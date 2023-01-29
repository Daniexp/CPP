#include <ex03.hpp>
# include <Fixed.hpp>
# include <Point.hpp>
# include <string>
# include <ctime>
# include <cstdlib>
# include <iostream>
void printValues(const Fixed& src)
{
	std::cout << "-------------" << std::endl;
	std::cout << src.getRawBits() << " " << src.getBinary() << std::endl;
	std::cout << "-------------" << std::endl;
}
void printBinary(const int num)
{
	int bit = 0;
	for (int i= 31; i>= 0; i--)
	{
		bit = (num >> i) & 1;
		std::cout << bit << std::endl;
	}
}
int main(void)
{
	std::srand(std::time(0));
	std::cout << "------------------------" << std::endl;
	Fixed ej;
	ej = Fixed(1111);
	printValues(ej);
	Fixed copia;
	copia = ej;
	printValues(copia);
	std::cout << "------------------------" << std::endl;
	std::cout << std::bitset<32>(-111) << std::endl;
	std::cout << std::bitset<32>(111) << std::endl;
	Fixed x(-111);
	std::cout << std::bitset<32>(x.getRawBits()) << std::endl;
	std::cout << x.toInt() << std::endl;
	x = Fixed(-111.156f);
	std::cout << std::bitset<32>(x.getRawBits()) << std::endl;
	std::cout << x.toFloat() << std::endl;
	std::cout << "------------------------" << std::endl;
Fixed a;
Fixed const b( 10 );
Fixed const c( 42.42f );
Fixed const d( b );
a = Fixed( 1234.4321f );
std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;
std::cout << "a is " << a.toInt() << " as integer" << std::endl;
std::cout << "b is " << b.toInt() << " as integer" << std::endl;
std::cout << "c is " << c.toInt() << " as integer" << std::endl;
std::cout << "d is " << d.toInt() << " as integer" << std::endl;
std::cout << "----------------" << std::endl;
std::cout << (c > a) << std::endl;
std::cout << (c + a) << std::endl;
std::cout << (c - a) << std::endl;
std::cout << (c * a) << std::endl;
std::cout << (c / a) << std::endl;
std::cout << ++(c / a) << std::endl;
std::cout << --(c / a) << std::endl;
std::cout << (c / a)++ << std::endl;
std::cout << "----------------" << std::endl;
std::cout << c.min(a, c) << std::endl;
std::cout << "----------------" << std::endl;
std::cout << "----------------" << std::endl;
std::cout << ((bsp(Point(0.0f,100.0f), Point(100.0f, 0.0f), Point(0.0f,0.0f), Point(10.0f,10.0f)))? "T" : "F") << std::endl;
std::cout << ((bsp(Point(0.0f,100.0f), Point(100.0f, 0.0f), Point(0.0f,0.0f), Point(0.0f,0.0f)))? "T" : "F") << std::endl;
std::cout << "----------------" << std::endl;
std::cout << "----------------" << std::endl;
int n = 10;
	Point v1(100.0f, 0.0f);
	Point v2(0.0f, 0.0f);
	Point v3(0.0f, 100.0f);
	std::cout << "v1: 100/0 v2: 0/0 v3: 0/100" << std::endl;
  for (int i = 0; i < n; i++) {
    float x =  (float) rand() /(float) RAND_MAX * 100.0;
    float y =  (float) rand() /(float) RAND_MAX * 100.0;
	Point ej(x, y);
    std::cout << "Point " << i+1 << ": x = " << x << ", y = " << y << ((bsp(v1,v2,v3,ej))? " True":" False") <<  std::endl;
  }
std::cout << "----------------" << std::endl;
}
