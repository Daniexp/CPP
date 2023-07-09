#include <Intern.hpp>

Intern::Intern()
{
//Const
	formName[0] = "presidential pardon";
	formName[1] = "robotomy request";
	formName[2] = "shrubbery creation";
}

Intern::Intern(const Intern& src)
{
//Copy Const
	*this = src;
}

Intern::~Intern()
{
//Dest
}

Intern& Intern::operator = (const Intern& src)
{
	if (this != &src)
	{
		formName[0] = src.formName[0];
		formName[1] = src.formName[1];
		formName[2] = src.formName[2];
	}
	return *this;
}

AForm	*Intern::makeForm(const std::string& name, const std::string& target)
{
	AForm *newForm;
	int i = 0;
	while (i < 3 && formName[i] != name)
		i++;
	switch (i)
	{
		case (0):
			newForm = new PresidentialPardonForm(target);
			break;
		case (1):
			newForm = new RobotomyRequestForm(target);
			break;
		case (2):
			newForm = new ShrubberyCreationForm(target);
			break;
		default:
			newForm = NULL;
			break;
	}
	return newForm;
}
