#include <ex06.hpp>
#include <HarlF.hpp>
int main(void)
{
	std::cout << "The proyect was created sucessfully." << std::endl;
	HarlF	harlcito;
	harlcito.complain("ERROR");
	std::cout << "-------------" << std::endl;
	harlcito.complain("DEBUG");
}
