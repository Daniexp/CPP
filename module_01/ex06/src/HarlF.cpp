#include "HarlF.hpp"
 
HarlF::HarlF()
{
//Const
}
HarlF::~HarlF()
{
//Dest
}
void HarlF::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}
void HarlF::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void HarlF::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void HarlF::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
void HarlF::complain(std::string level)
{
	std::string tag[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (HarlF::*levelFunc[])(void) = {&HarlF::debug, &HarlF::info, &HarlF::warning, &HarlF::error};
	int i=0;
	while (i < 4 && tag[i] != level)
		i++;
//			(this->*levelFunc[i])();
	switch(i)
	{
		case 0:
			(this->*levelFunc[0])();
		case 1:
			(this->*levelFunc[1])();
		case 2:
			(this->*levelFunc[2])();
		case 3:
			(this->*levelFunc[3])();
			break;
		case 4:
			std::cout << "Invalid level" << std::endl;
	}
};
