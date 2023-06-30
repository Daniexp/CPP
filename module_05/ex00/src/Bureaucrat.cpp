#include <Bureaucrat.hpp>

//Bureaucraft
Bureaucrat::Bureaucrat() : name(""), grade(1)
{
//Const
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
{
//Copy Const
	*this = src;
}

Bureaucrat::Bureaucrat(const std::string& _name, int _grade) : name(_name)
{
	if (_grade < 1)
		throw GradeTooHighExcept();
	else if (_grade > 150)
		throw GradeTooLowExcept();
	else
		grade = _grade;
}

Bureaucrat::~Bureaucrat()
{
//Dest
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& src)
{
	if (this != &src)
		this->grade = src.getGrade();
	return *this;
}

const std::string& Bureaucrat::getName(void) const
{
	return name;
}

int Bureaucrat::getGrade(void) const
{
	return grade;
}

void Bureaucrat::incrementGrade(void)
{
	if (grade - 1 < 1)
		throw GradeTooHighExcept();
	else
		grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if (grade + 1 > 1)
		throw GradeTooLowExcept();
	else
		grade++;
}

std::ostream& operator << (std::ostream& os, const Bureaucrat& src)
{
	os << "I'm a Bureocraft, my name is " << src.getName() << " and my grade is: " << src.getGrade() << std::endl;
	return os;
}
