//#include <ex00.hpp>
#include <Zombie.hpp>

Zombie* newZombie( std::string name)
{
	//std::cout << name << std::endl;
	return (new Zombie(name));
}
