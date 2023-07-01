#include <test.hpp>

void	testForm(int messageLength, char fillchar)
{
	imprimirCentrado("TEST FORM", messageLength, fillchar);
	std::cout << std::endl;

	testFormCreateInvalidGrade();

	tryCatch(testFormGetters);

	testFormBeSigned();

	testBureaucratSignForm();

	imprimirCentrado("END", messageLength, fillchar);
}
void	testFormCreateInvalidSignGradeTooLow(void)
{
	std::cout << "Trying to create a Form with a SignGrade of 151" << std::endl;
	Form formExample = Form("Example form", 1, 151);
	std::cout << formExample;
}
void	testFormCreateInvalidSignGradeTooHigh(void)
{
	std::cout << "Trying to create a Form with a SignGrade of 0" << std::endl;
	Form formExample = Form("Example form", 1, 0);
	std::cout << formExample;
}
void	testFormCreateInvalidSignGrade(void)
{
	tryCatch(testFormCreateInvalidSignGradeTooLow);
	tryCatch(testFormCreateInvalidSignGradeTooHigh);
}
void	testFormCreateInvalidExecGradeTooLow(void)
{
	std::cout << "Trying to create a Form with a ExecGrade of 151" << std::endl;
	Form formExample = Form("Example form", 151, 1);
	std::cout << formExample;
}
void	testFormCreateInvalidExecGradeTooHigh(void)
{
	std::cout << "Trying to create a Form with a ExecGrade of 0" << std::endl;
	Form formExample = Form("Example form", 0, 1);
	std::cout << formExample;
}
void	testFormCreateInvalidExecGrade(void)
{
	tryCatch(testFormCreateInvalidExecGradeTooLow);
	tryCatch(testFormCreateInvalidExecGradeTooHigh);
}
void	testFormCreateInvalidGrade(void)
{
	tryCatch(testFormCreateInvalidSignGrade);
	tryCatch(testFormCreateInvalidExecGrade);
}
void	testFormGetters(void)
{
	std::cout << "Call Form getters" << std::endl;
	Form applyForm = Form("Apply form", 1,150);
	std::cout << applyForm;
	std::cout << "Name : " << applyForm.getName() << std::endl;
	std::cout << "IsSigned : " << applyForm.getIsSigned() << std::endl;
	std::cout << "ExecGrade : " << applyForm.getExecGrade() << std::endl;
	std::cout << "SignGrade : " << applyForm.getSignGrade() << std::endl;
}
void	testFromBeSignedInvalid(void)
{
	std::cout << "Trying to sign a Form with a ExecGrade bigger than the Bureaucrat one's" << std::endl;
	Form formExample = Form("Example form", 150, 1);
	Bureaucrat Jhon = Bureaucrat("Jhon", 150);
	std::cout << formExample;
	std::cout << Jhon;
	formExample.beSigned(Jhon);
	std::cout << formExample;
}
void	testFromBeSignedValid(void)
{
	std::cout << "Trying to sign a Form with a ExecGrade smaller than the Bureaucrat one's" << std::endl;
	Form formExample = Form("Example form", 1, 150);
	Bureaucrat Jhon = Bureaucrat("Jhon", 1);
	std::cout << formExample;
	std::cout << Jhon;
	formExample.beSigned(Jhon);
	std::cout << formExample;
}
void	testFormBeSigned(void)
{
	tryCatch(testFromBeSignedInvalid);
	tryCatch(testFromBeSignedValid);
}
void	testBureaucratSignFormInvalid(void)
{
	std::cout << "Bureaucrat trying to sign a form with less signGrade than the require one" << std::endl;
	Form formExample = Form("Example form", 150, 50);
	Bureaucrat Jhon = Bureaucrat("Jhon", 100);
	std::cout << formExample;
	std::cout << Jhon;
	Jhon.signForm(formExample);
	std::cout << formExample;
}
void	testBureaucratSignFormValid(void)
{
	std::cout << "Bureaucrat trying to sign a form with more signGrade than the require one" << std::endl;
	Form formExample = Form("Example form", 150, 100);
	Bureaucrat Jhon = Bureaucrat("Jhon", 50);
	std::cout << formExample;
	std::cout << Jhon;
	Jhon.signForm(formExample);
	std::cout << formExample;
}
void	testBureaucratSignForm(void)
{
	tryCatch(testBureaucratSignFormInvalid);
	tryCatch(testBureaucratSignFormValid);
}
