#include <iostream>
#include <string>

int	main(void)
{
	std::string	strEj="HI THIS IS BRAIN";
	std::string*	stringPTR = &strEj;
	std::string&	stringREF = strEj;

	std::cout << "La dirección de memoria de la variable de tipo string: " << &strEj << std::endl << "La dirección de memoria contenida en stringPTR: " << stringPTR << std::endl <<  "La dirección de memoria contenida en stringREF: " << &stringREF << std::endl;
	std::cout << "El valor de la varible string: " << strEj << std::endl << "El valor apuntado por stringPTR: " << *stringPTR << std::endl << "El valor apuntado por stringREF: " << stringREF << std::endl;
}
