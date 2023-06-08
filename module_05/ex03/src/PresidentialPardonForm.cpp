#include <PresidentialPardonForm.hpp>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm(target, 5, 25)
{
//Const
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
{
//Copy Const
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
//Dest
}

PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm& src)
{
	if (this != &src)
		std::cout << "There is nothing to do..." << std::endl;
	return *this;
}

void PresidentialPardonForm::doAction(const std::string& target) const
{
	std::cout << target << " have been pardoned by Zaphod Beeblebrox." << std::endl;
}
