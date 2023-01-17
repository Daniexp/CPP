#include "Zombie.hpp"
 
Zombie::Zombie()
{
//Const
}
 
Zombie::Zombie( std::string name)
{
	Name = name;
	std::cout << "The Zombie " << name << " wake up of a remote graveyard." << std::endl;
}

Zombie::~Zombie()
{
//Dest
	if(!Name.empty())
	std::cout << "The Zombie " << Name << " return to the graveyard where he comes from..." << std::endl;
}

void Zombie::announce( void )
{
	if (!Name.empty())
		std::cout << Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


