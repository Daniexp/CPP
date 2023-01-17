#ifndef MAINHEADER_H
#define MAINHEADER_H
# include <iostream>
# include <Zombie.hpp>
typedef	std::basic_string<char> str;
Zombie*	newZombie( std::string name);
void	randomChump( std::string name );
Zombie*	zombieHorde( int N, std::string name );

#endif
