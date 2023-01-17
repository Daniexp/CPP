#include <mainHeader.hpp>
#include <Zombie.hpp>
int main(void)
{
	int sizeHorde = 10;
	std::cout << "The proyect was created sucessfully." << std::endl;
	Zombie* horde = zombieHorde(sizeHorde, "Pulgarcito");
	for (int i=0; i < sizeHorde; i++)
		horde[i].announce();
	delete[] horde;
}
