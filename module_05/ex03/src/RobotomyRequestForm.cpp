#include <RobotomyRequestForm.hpp>

RobotomyRequestForm::RobotomyRequestForm()
{
//Const
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
{
//Copy Const
	*this = src;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm(target, 45, 72)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
//Dest
}

RobotomyRequestForm& RobotomyRequestForm::operator = (const RobotomyRequestForm& src)
{
	if (this != &src)
		std::cout << "NO se que hacer aqui" << std::endl;
	return *this;
}

void RobotomyRequestForm::doAction( const std::string& target) const
{
	std::srand(static_cast<unsigned int> (std::time(nullptr)));
	int random;

	random = 0 + (std::rand() % (1 - 0 + 1));
	(random == 1) ? std::cout << target << " has been robotomized successfully." << std::endl : std::cout << "The robotomy of " << target << " failed." << std::endl;
}
