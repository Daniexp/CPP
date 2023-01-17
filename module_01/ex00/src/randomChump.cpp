#include <ex00.hpp>
#include <Zombie.hpp>

void	randomChump( std::string name)
{
	Zombie zombie= Zombie(name);
	zombie.announce();
}
