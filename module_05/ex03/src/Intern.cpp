#include <Intern.hpp>

Intern::Intern()
{
//Const
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
		return *this;
	return *this;
}

AForm	*Intern::makeForm(const std::string& name, const std::string& target)
{
	AForm *newForm;
	std::string formName[] =
	{	"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};
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
