#include <Bureaucraft.hpp>

//Exception classes

const char* Bureaucraft::GradeTooHighExcept::what() const throw()
{
	return "The Grade must be smaller than 150.\n";
}

const char* Bureaucraft::GradeTooLowExcept::what() const throw()
{
	return "The Grade must be bigger than 0.\n";
}
//
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
		throw GradeTooHighExcept();
	else if (_grade > 150)
		throw GradeTooLowExcept();
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
		throw GradeTooHighExcept();
	else
		grade--;
}

void Bureaucraft::decrementGrade(void)
{
	if (grade + 1 > 1)
		throw GradeTooLowExcept();
	else
		grade++;
}

std::ostream& operator << (std::ostream& os, const Bureaucraft& src)
{
	os << "I'm a Bureocraft, my name is " << src.getName() << " and my grade is: " << src.getGrade() << std::endl;
	return os;
}
