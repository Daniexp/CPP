#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <iostream>
#include <string>
class	Zombie
{
	public:
	Zombie();
	Zombie( std::string name );
	~Zombie();
	void announce( void );
	private:
	std::string Name;
};

#endif //ZOMBIE_H


