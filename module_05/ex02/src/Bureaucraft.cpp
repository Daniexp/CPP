#include <Bureaucraft.hpp>

//Bureaucraft
Bureaucraft::Bureaucraft() : name(""), grade(1)
{
//Const
}

Bureaucraft::Bureaucraft(const Bureaucraft& src)
{
//Copy Const
	*this = src;
}

Bureaucraft::Bureaucraft(const std::string& _name, int _grade) : name(_name)
{
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
	else
		grade = _grade;
}

Bureaucraft::~Bureaucraft()
{
//Dest
}

Bureaucraft& Bureaucraft::operator = (const Bureaucraft& src)
{
	if (this != &src)
		this->grade = src.getGrade();
	return *this;
}

const std::string& Bureaucraft::getName(void) const
{
	return name;
}

int Bureaucraft::getGrade(void) const
{
	return grade;
}

void Bureaucraft::incrementGrade(void)
{
	if (grade - 1 < 1)
		throw GradeTooHighException();
	else
		grade--;
}

void Bureaucraft::decrementGrade(void)
{
	if (grade + 1 > 1)
		throw GradeTooLowException();
	else
		grade++;
}

void Bureaucraft::signForm(const AForm& form) const
{
	if (form.getIsSigned() == true)
		std::cout << getName() << " signed " << form.getName() << std::endl;
	else
		std::cout << getName() << "couldn't sign " << form.getName() << " because the signGrade of the form is " << form.getSignGrade() << " and mine is " << getGrade() << std::endl;
}

std::ostream& operator << (std::ostream& os, const Bureaucraft& src)
{
	os << "I'm a Bureocraft, my name is " << src.getName() << " and my grade is: " << src.getGrade() << std::endl;
	return os;
}
