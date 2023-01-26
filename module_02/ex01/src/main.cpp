#include <ex01.hpp>
# include <Fixed.hpp>
void printValues(const Fixed& src)
{
	std::cout << "-------------" << std::endl;
	std::cout << src.getRawBits() << " " << src.getBinary() << std::endl;
	std::cout << "-------------" << std::endl;
}
int main(void)
{
	std::cout << "The proyect was created sucessfully." << std::endl;
	Fixed ej;
	ej = Fixed(1111);
	printValues(ej);
	Fixed copia;
	copia = ej;
	printValues(copia);
	std::cout << "------------------------" << std::endl;
	Fixed a;
Fixed b( a );
Fixed c;
c = b;
std::cout << a.getRawBits() << std::endl;
std::cout << b.getRawBits() << std::endl;
std::cout << c.getRawBits() << std::endl;
}
