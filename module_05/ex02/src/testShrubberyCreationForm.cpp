#include <test.hpp>

void	testShrubberyCreationForm(int messageLength, char fillchar)
{
	imprimirCentrado("TEST FORM", messageLength, fillchar);
	std::cout << std::endl;

	testShrubberyCreationFormCreateInvalidGrade();

	tryCatch(testShrubberyCreationFormGetters);

	testShrubberyCreationFormBeSigned();

	testBureaucratSignShrubberyCreationForm();

	imprimirCentrado("END", messageLength, fillchar);
}
void	testShrubberyCreationFormCreateInvalidSignGradeTooLow(void)
{
	std::cout << "Trying to create a ShrubberyCreationForm with a SignGrade of 151" << std::endl;
	ShrubberyCreationForm formExample = ShrubberyCreationForm("example");
	std::cout << formExample;
}
void	testShrubberyCreationFormCreateInvalidSignGradeTooHigh(void)
{
	std::cout << "Trying to create a ShrubberyCreationForm with a SignGrade of 0" << std::endl;
	ShrubberyCreationForm formExample = ShrubberyCreationForm("example");
	std::cout << formExample;
}
void	testShrubberyCreationFormCreateInvalidSignGrade(void)
{
	tryCatch(testShrubberyCreationFormCreateInvalidSignGradeTooLow);
	tryCatch(testShrubberyCreationFormCreateInvalidSignGradeTooHigh);
}
void	testShrubberyCreationFormCreateInvalidExecGradeTooLow(void)
{
	std::cout << "Trying to create a ShrubberyCreationForm with a ExecGrade of 151" << std::endl;
	ShrubberyCreationForm formExample = ShrubberyCreationForm("example");
	std::cout << formExample;
}
void	testShrubberyCreationFormCreateInvalidExecGradeTooHigh(void)
{
	std::cout << "Trying to create a ShrubberyCreationForm with a ExecGrade of 0" << std::endl;
	ShrubberyCreationForm formExample = ShrubberyCreationForm("example");
	std::cout << formExample;
}
void	testShrubberyCreationFormCreateInvalidExecGrade(void)
{
	tryCatch(testShrubberyCreationFormCreateInvalidExecGradeTooLow);
	tryCatch(testShrubberyCreationFormCreateInvalidExecGradeTooHigh);
}
void	testShrubberyCreationFormCreateInvalidGrade(void)
{
	tryCatch(testShrubberyCreationFormCreateInvalidSignGrade);
	tryCatch(testShrubberyCreationFormCreateInvalidExecGrade);
}
void	testShrubberyCreationFormGetters(void)
{
	std::cout << "Call ShrubberyCreationForm getters" << std::endl;
	ShrubberyCreationForm applyShrubberyCreationForm = ShrubberyCreationForm("Applyform");
	std::cout << applyShrubberyCreationForm;
	std::cout << "Name : " << applyShrubberyCreationForm.getName() << std::endl;
	std::cout << "IsSigned : " << applyShrubberyCreationForm.getIsSigned() << std::endl;
	std::cout << "ExecGrade : " << applyShrubberyCreationForm.getExecGrade() << std::endl;
	std::cout << "SignGrade : " << applyShrubberyCreationForm.getSignGrade() << std::endl;
}
void	testFromBeSignedInvalid(void)
{
	std::cout << "Trying to sign a ShrubberyCreationForm with a ExecGrade bigger than the Bureaucrat one's" << std::endl;
	ShrubberyCreationForm formExample = ShrubberyCreationForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 150);
	std::cout << formExample;
	std::cout << Jhon;
	formExample.beSigned(Jhon);
	std::cout << formExample;
}
void	testFromBeSignedValid(void)
{
	std::cout << "Trying to sign a ShrubberyCreationForm with a ExecGrade smaller than the Bureaucrat one's" << std::endl;
	ShrubberyCreationForm formExample = ShrubberyCreationForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 1);
	std::cout << formExample;
	std::cout << Jhon;
	formExample.beSigned(Jhon);
	std::cout << formExample;
}
void	testShrubberyCreationFormBeSigned(void)
{
	tryCatch(testFromBeSignedInvalid);
	tryCatch(testFromBeSignedValid);
}
void	testBureaucratSignShrubberyCreationFormInvalid(void)
{
	std::cout << "Bureaucrat trying to sign a form with less signGrade than the require one" << std::endl;
	ShrubberyCreationForm formExample = ShrubberyCreationForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 100);
	std::cout << formExample;
	std::cout << Jhon;
	Jhon.signForm(formExample);
	std::cout << formExample;
}
void	testBureaucratSignShrubberyCreationFormValid(void)
{
	std::cout << "Bureaucrat trying to sign a form with more signGrade than the require one" << std::endl;
	ShrubberyCreationForm formExample = ShrubberyCreationForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 50);
	std::cout << formExample;
	std::cout << Jhon;
	Jhon.signForm(formExample);
	std::cout << formExample;
}
void	testBureaucratSignShrubberyCreationForm(void)
{
	tryCatch(testBureaucratSignShrubberyCreationFormInvalid);
	tryCatch(testBureaucratSignShrubberyCreationFormValid);
}
