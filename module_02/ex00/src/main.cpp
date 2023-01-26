#include <ex00.hpp>
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
}
