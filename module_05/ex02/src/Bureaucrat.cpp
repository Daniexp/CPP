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
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
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
		throw GradeTooHighException();
	else
		grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if (grade + 1 > 150)
		throw GradeTooLowException();
	else
		grade++;
}

void Bureaucrat::signForm(AForm& form) const
{
	if (form.getIsSigned() == false)
		try
		{
			form.beSigned(*this);
			std::cout << getName() << " signed " << form.getName() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << getName() << " couldn't sign " << form.getName() << " because " << e.what() << "The signGrade of the form is " << form.getSignGrade() << " and the Bureaucrat have " << getGrade() << std::endl;
			std::cout << getName() << " couldn't sign " << form.getName() << " because the signGrade of the form is " << form.getSignGrade() << " and the Bureaucrat have " << getGrade() << std::endl;
		}
	else
		std::cout << getName() << " couldn't sign " << form.getName() << " because the form is already signed..." << std::endl;
}

std::ostream& operator << (std::ostream& os, const Bureaucrat& src)
{
	os << "I'm a Bureocraft, my name is " << src.getName() << " and my grade is: " << src.getGrade() << std::endl;
	return os;
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << getName() << " executed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << getName() << " couldn't sign the form because ";
		if (typeid(FormNotSignedException) == typeid(e))
			std::cerr << "the form must to be signed to be execute";
		else if (typeid(e) == typeid(GradeTooLowException))
			std::cerr << "the execGrade of the form is " << form.getExecGrade() << " and the Bureaucrat have " << getGrade();
		else
			std::cerr << "of an unknowm exception...";
		std:: cerr << std::endl;
	}
}
