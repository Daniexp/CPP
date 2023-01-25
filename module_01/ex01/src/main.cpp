#include <mainHeader.hpp>
#include <Zombie.hpp>
int main(void)
{
	int sizeHorde = 10;
	Zombie* horde = zombieHorde(sizeHorde, "Pulgarcito");
	for (int i=0; i < sizeHorde; i++)
		horde[i].announce();
	delete[] horde;
}
