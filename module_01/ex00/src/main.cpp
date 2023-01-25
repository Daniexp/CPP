#include <ex00.hpp>
#include <Zombie.hpp>
int main(void)
{
	Zombie ejStack = Zombie("Pepe");
	Zombie *ejHeap = newZombie("Juan");
	randomChump("Manolo");
	ejHeap->announce();
	ejStack.announce();
	delete (ejHeap);
}
