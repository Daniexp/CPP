#include <AForm.hpp>

AForm::AForm() : name(""), isSigned(false), execGrade(150), signGrade(1)
{
//Const
}

AForm::AForm(const AForm& src) : name(src.getName()), isSigned(src.getIsSigned()), execGrade(src.getExecGrade()), signGrade(src.getSignGrade())
{
//Copy Const
//	*this = src;
}

AForm::AForm(const std::string& _name) : name(_name), isSigned(0) , execGrade(150), signGrade(1)
{}

AForm::AForm(const std::string& _name, const int exec, const int sign) : name(_name), isSigned(0), execGrade(exec), signGrade(sign)
{
	if (exec < 1 || sign < 1)
		throw GradeTooHighException();
	else if (exec > 150 || sign > 150)
		throw GradeTooLowException();
}

AForm::~AForm()
{
//Dest
}

AForm& AForm::operator = (const AForm& src)
{
	if (this != &src)
		isSigned = src.getIsSigned();
	return *this;
}

const std::string&  AForm::getName() const
{
	return name;
}

bool AForm::getIsSigned() const
{
	return isSigned;
}

int AForm::getExecGrade() const
{
	return execGrade;
}

int AForm::getSignGrade() const
{
	return signGrade;
}

void AForm::beSigned(const Bureaucraft& bureau)
{
	if (bureau.getGrade() < getSignGrade())
		throw GradeTooLowException();
	else
		isSigned = true;
}

std::ostream& operator << (std::ostream& os, const AForm& src)
{
	os << "Form name: " << src.getName() << ", is signed: " << src.getIsSigned() << ", execution grade: " << src.getExecGrade() << " and sign grade" << src.getSignGrade() << std::endl;
	return os;
}

void AForm::setIsSigned(bool value)
{
	isSigned = value;
}

void AForm::execute(Bureaucraft const & executor) const
{
	if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException();
	else if (getIsSigned() == true)
		doAction(getName());
	else
		throw FormNotSignedException();
		 //tirar que le form no esta signed
}
