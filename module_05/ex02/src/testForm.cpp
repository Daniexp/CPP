#include <test.hpp>

void	testAForm(int messageLength, char fillchar)
{
	imprimirCentrado("TEST FORM", messageLength, fillchar);
	std::cout << std::endl;

	testAFormCreateInvalidGrade();

	tryCatch(testAFormGetters);

	testAFormBeSigned();

	testBureaucratSignAForm();

	imprimirCentrado("END", messageLength, fillchar);
}
void	testAFormCreateInvalidSignGradeTooLow(void)
{
	std::cout << "Trying to create a AForm with a SignGrade of 151" << std::endl;
	AForm formExample = AForm("Example form", 1, 151);
	std::cout << formExample;
}
void	testAFormCreateInvalidSignGradeTooHigh(void)
{
	std::cout << "Trying to create a AForm with a SignGrade of 0" << std::endl;
	AForm formExample = AForm("Example form", 1, 0);
	std::cout << formExample;
}
void	testAFormCreateInvalidSignGrade(void)
{
	tryCatch(testAFormCreateInvalidSignGradeTooLow);
	tryCatch(testAFormCreateInvalidSignGradeTooHigh);
}
void	testAFormCreateInvalidExecGradeTooLow(void)
{
	std::cout << "Trying to create a AForm with a ExecGrade of 151" << std::endl;
	AForm formExample = AForm("Example form", 151, 1);
	std::cout << formExample;
}
void	testAFormCreateInvalidExecGradeTooHigh(void)
{
	std::cout << "Trying to create a AForm with a ExecGrade of 0" << std::endl;
	AForm formExample = AForm("Example form", 0, 1);
	std::cout << formExample;
}
void	testAFormCreateInvalidExecGrade(void)
{
	tryCatch(testAFormCreateInvalidExecGradeTooLow);
	tryCatch(testAFormCreateInvalidExecGradeTooHigh);
}
void	testAFormCreateInvalidGrade(void)
{
	tryCatch(testAFormCreateInvalidSignGrade);
	tryCatch(testAFormCreateInvalidExecGrade);
}
void	testAFormGetters(void)
{
	std::cout << "Call AForm getters" << std::endl;
	AForm applyAForm = AForm("Apply form", 1,150);
	std::cout << applyAForm;
	std::cout << "Name : " << applyAForm.getName() << std::endl;
	std::cout << "IsSigned : " << applyAForm.getIsSigned() << std::endl;
	std::cout << "ExecGrade : " << applyAForm.getExecGrade() << std::endl;
	std::cout << "SignGrade : " << applyAForm.getSignGrade() << std::endl;
}
void	testFromBeSignedInvalid(void)
{
	std::cout << "Trying to sign a AForm with a ExecGrade bigger than the Bureaucrat one's" << std::endl;
	AForm formExample = AForm("Example form", 150, 1);
	Bureaucrat Jhon = Bureaucrat("Jhon", 150);
	std::cout << formExample;
	std::cout << Jhon;
	formExample.beSigned(Jhon);
	std::cout << formExample;
}
void	testFromBeSignedValid(void)
{
	std::cout << "Trying to sign a AForm with a ExecGrade smaller than the Bureaucrat one's" << std::endl;
	AForm formExample = AForm("Example form", 1, 150);
	Bureaucrat Jhon = Bureaucrat("Jhon", 1);
	std::cout << formExample;
	std::cout << Jhon;
	formExample.beSigned(Jhon);
	std::cout << formExample;
}
void	testAFormBeSigned(void)
{
	tryCatch(testFromBeSignedInvalid);
	tryCatch(testFromBeSignedValid);
}
void	testBureaucratSignAFormInvalid(void)
{
	std::cout << "Bureaucrat trying to sign a form with less signGrade than the require one" << std::endl;
	AForm formExample = AForm("Example form", 150, 50);
	Bureaucrat Jhon = Bureaucrat("Jhon", 100);
	std::cout << formExample;
	std::cout << Jhon;
	Jhon.signAForm(formExample);
	std::cout << formExample;
}
void	testBureaucratSignAFormValid(void)
{
	std::cout << "Bureaucrat trying to sign a form with more signGrade than the require one" << std::endl;
	AForm formExample = AForm("Example form", 150, 100);
	Bureaucrat Jhon = Bureaucrat("Jhon", 50);
	std::cout << formExample;
	std::cout << Jhon;
	Jhon.signAForm(formExample);
	std::cout << formExample;
}
void	testBureaucratSignAForm(void)
{
	tryCatch(testBureaucratSignAFormInvalid);
	tryCatch(testBureaucratSignAFormValid);
}
