#include <ex02.hpp>
# include <Fixed.hpp>
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
	std::cout << "The proyect was created sucessfully." << std::endl;
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
//	printBinary(x.getRawBits());
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

}
