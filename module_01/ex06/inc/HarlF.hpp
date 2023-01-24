#ifndef HARLF_H
#define HARLF_H
# include <iostream>
# include <string>

class	HarlF
{
	public:
	HarlF();
	~HarlF();
	void	complain( std::string level);
	private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
};
#endif //HARL_H
