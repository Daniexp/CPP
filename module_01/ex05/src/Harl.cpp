#include "Harl.hpp"
 
Harl::Harl()
{
//Const
}
Harl::~Harl()
{
//Dest
}
void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}
void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
void Harl::complain(std::string level)
{
	std::string tag[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*levelFunc[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i=0; i < 4; i++)
		if (level == tag[i])
			(this->*levelFunc[i])();
/*	switch(level.c_str())
	{
		case "DEBUG":
			lv = 0;
			break;
		case "INFO":
			lv = 1;
			break;
		case "WARNING":
			lv = 2;
			break;
		case "ERROR":
			lv = 3;
			break;
		default:
			std::cout << "Invalid level" << std::endl;
			return ;
	}
	(this->*levelFunc[lv])();
	*/
};
