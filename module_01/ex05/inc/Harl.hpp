#ifndef HARL_H
#define HARL_H
# include <iostream>
# include <string>

class	Harl
{
	public:
	Harl();
	~Harl();
	void	complain( std::string level);
	private:
//	void	(Harl::*levelFunc[])(void);
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
};
#endif //HARL_H
