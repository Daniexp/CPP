#include <Form.hpp>

Form::Form() : name(""), isSigned(false), execGrade(150), signGrade(1)
{
//Const
}

Form::Form(const Form& src) : name(src.getName()), isSigned(src.getIsSigned()), execGrade(src.getExecGrade()), signGrade(src.getSignGrade())
{
//Copy Const
//	*this = src;
}

Form::Form(const std::string& _name) : name(_name), isSigned(0) , execGrade(150), signGrade(1)
{}

Form::Form(const std::string& _name, const int exec, const int sign) : name(_name), isSigned(0), execGrade(exec), signGrade(sign)
{
	if (exec < 1 || sign < 1)
		throw GradeTooHighException();
	else if (exec > 150 || sign > 150)
		throw GradeTooLowException();
}

Form::~Form()
{
//Dest
}

Form& Form::operator = (const Form& src)
{
	if (this != &src)
		isSigned = src.getIsSigned();
	return *this;
}

const std::string&  Form::getName() const
{
	return name;
}

bool Form::getIsSigned() const
{
	return isSigned;
}

int Form::getExecGrade() const
{
	return execGrade;
}

int Form::getSignGrade() const
{
	return signGrade;
}

void Form::beSigned(const Bureaucrat& bureau)
{
	if (bureau.getGrade() < getSignGrade())
		throw GradeTooLowException();
	else
		isSigned = true;
}

std::ostream& operator << (std::ostream& os, const Form& src)
{
	os << "Form name: " << src.getName() << ", is signed: " << src.getIsSigned() << ", execution grade: " << src.getExecGrade() << " and sign grade" << src.getSignGrade() << std::endl;
	return os;
}
