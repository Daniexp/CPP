#include <ex00.hpp>
#include <Zombie.hpp>
int main(void)
{
	std::cout << "The proyect was created sucessfully." << std::endl;
	Zombie ejStack = Zombie("Pepe");
	Zombie *ejHeap = newZombie("Juan");
	randomChump("Manolo");
	ejStack.announce();
	ejHeap->announce();
	delete (ejHeap);
}
