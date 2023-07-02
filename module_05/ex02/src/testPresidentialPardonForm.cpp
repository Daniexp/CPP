#include <test.hpp>

void	testPresidentialPardonForm(int messageLength, char fillchar)
{
	imprimirCentrado("TEST PRESIDENTIALPARDONFORM", messageLength, fillchar);
	std::cout << std::endl;

	tryCatch(testPresidentialPardonFormGetters);

	testPresidentialPardonFormBeSigned();

	testBureaucratSignPresidentialPardonForm();

	testPresidentialPardonFormExecute();

	testBureaucratExecPresidentialPardonForm();

	imprimirCentrado("END", messageLength, fillchar);
}
void	testPresidentialPardonFormGetters(void)
{
	std::cout << "Call PresidentialPardonForm getters" << std::endl;
	PresidentialPardonForm applyPresidentialPardonForm = PresidentialPardonForm("Applyform");
	std::cout << applyPresidentialPardonForm;
	std::cout << "Name : " << applyPresidentialPardonForm.getName() << std::endl;
	std::cout << "IsSigned : " << applyPresidentialPardonForm.getIsSigned() << std::endl;
	std::cout << "ExecGrade : " << applyPresidentialPardonForm.getExecGrade() << std::endl;
	std::cout << "SignGrade : " << applyPresidentialPardonForm.getSignGrade() << std::endl;
}
void	testPresidentialPardonFormBeSignedInvalid(void)
{
	std::cout << "Trying to sign a PresidentialPardonForm with a ExecGrade bigger than the Bureaucrat one's" << std::endl;
	PresidentialPardonForm formExample = PresidentialPardonForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 146);
	std::cout << formExample;
	std::cout << Jhon;
	formExample.beSigned(Jhon);
	std::cout << formExample;
}
void	testPresidentialPardonFormBeSignedValid(void)
{
	std::cout << "Trying to sign a PresidentialPardonForm with a ExecGrade smaller than the Bureaucrat one's" << std::endl;
	PresidentialPardonForm formExample = PresidentialPardonForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 143);
	std::cout << formExample;
	std::cout << Jhon;
	formExample.beSigned(Jhon);
	std::cout << formExample;
}
void	testPresidentialPardonFormBeSigned(void)
{
	tryCatch(testPresidentialPardonFormBeSignedInvalid);
	tryCatch(testPresidentialPardonFormBeSignedValid);
}
void	testBureaucratSignPresidentialPardonFormInvalid(void)
{
	std::cout << "Bureaucrat trying to sign a PresidentialPardonForm with less signGrade than the require one" << std::endl;
	PresidentialPardonForm formExample = PresidentialPardonForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 146);
	std::cout << formExample;
	std::cout << Jhon;
	Jhon.signForm(formExample);
	std::cout << formExample;
}
void	testBureaucratSignPresidentialPardonFormValid(void)
{
	std::cout << "Bureaucrat trying to sign a PresidentialPardonForm with more signGrade than the require one" << std::endl;
	PresidentialPardonForm formExample = PresidentialPardonForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 143);
	std::cout << formExample;
	std::cout << Jhon;
	Jhon.signForm(formExample);
	std::cout << formExample;
}
void	testBureaucratSignPresidentialPardonForm(void)
{
	tryCatch(testBureaucratSignPresidentialPardonFormInvalid);
	tryCatch(testBureaucratSignPresidentialPardonFormValid);
}
void	testPresidentialPardonFormExecuteInvalidNotSigned(void)
{
	std::cout << "UNSIGNED FORM INVALID EXEC" << std::endl;
	std::cout << "Trying to execute a PresidentialPardonForm NotSigned with a ExecGrade bigger than the Bureaucrat one's" << std::endl;
	PresidentialPardonForm formExample = PresidentialPardonForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 136);
	std::cout << formExample;
	std::cout << Jhon;
	formExample.execute(Jhon);
	std::cout << formExample;
}
void	testPresidentialPardonFormExecuteInvalidSigned(void)
{
	std::cout << "SIGNED FORM INVALID EXEC" << std::endl;
	std::cout << "Trying to execute a PresidentialPardonForm Signed with a ExecGrade bigger than the Bureaucrat one's" << std::endl;
	PresidentialPardonForm formExample = PresidentialPardonForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 136);
	std::cout << formExample;
	std::cout << Jhon;
	formExample.beSigned(Jhon);
	formExample.execute(Jhon);
	std::cout << formExample;
}
void	testPresidentialPardonFormExecuteValidNotSigned(void)
{
	std::cout << "UNSIGNED FORM VALID EXEC" << std::endl;
	std::cout << "Trying to execute a PresidentialPardonForm NotSigned with a ExecGrade smaller than the Bureaucrat one's" << std::endl;
	PresidentialPardonForm formExample = PresidentialPardonForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 137);
	std::cout << formExample;
	std::cout << Jhon;
	formExample.execute(Jhon);
	std::cout << formExample;
}
void	testPresidentialPardonFormExecuteValidSigned(void)
{
	std::cout << "SIGNED FORM VALID EXEC" << std::endl;
	std::cout << "Trying to execute a PresidentialPardonForm Signed with a ExecGrade smaller than the Bureaucrat one's" << std::endl;
	PresidentialPardonForm formExample = PresidentialPardonForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 137);
	std::cout << formExample;
	std::cout << Jhon;
	formExample.beSigned(Jhon);
	formExample.execute(Jhon);
	std::cout << formExample;
}
void	testPresidentialPardonFormExecute(void)
{
	tryCatch(testPresidentialPardonFormExecuteInvalidNotSigned);
	tryCatch(testPresidentialPardonFormExecuteInvalidSigned);
	tryCatch(testPresidentialPardonFormExecuteValidNotSigned);
	tryCatch(testPresidentialPardonFormExecuteValidSigned);
}
void testBureaucratExecPresidentialPardonFormInvalidNotSigned(void)
{
	std::cout << "UNSIGNED FORM INVALID EXEC" << std::endl;
	std::cout << "Bureaucrat Trying to execute a PresidentialPardonForm NotSigned with a ExecGrade bigger than the Bureaucrat one's" << std::endl;
	PresidentialPardonForm formExample = PresidentialPardonForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 138);
	std::cout << formExample;
	std::cout << Jhon;
	Jhon.executeForm(formExample);
	std::cout << formExample;
}
void testBureaucratExecPresidentialPardonFormInvalidSigned(void)
{
	std::cout << "SIGNED FORM INVALID EXEC" << std::endl;
	std::cout << "Bureaucrat Trying to execute a PresidentialPardonForm Signed with a ExecGrade bigger than the Bureaucrat one's" << std::endl;
	PresidentialPardonForm formExample = PresidentialPardonForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 138);
	std::cout << formExample;
	std::cout << Jhon;
	Jhon.signForm(formExample);
	Jhon.executeForm(formExample);
	std::cout << formExample;
}
void testBureaucratExecPresidentialPardonFormValidNotSigned(void)
{
	std::cout << "NOT SIGNED FORM VALID EXEC" << std::endl;
	std::cout << "Bureaucrat Trying to execute a PresidentialPardonForm NotSigned with a ExecGrade smaller than the Bureaucrat one's" << std::endl;
	PresidentialPardonForm formExample = PresidentialPardonForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 137);
	std::cout << formExample;
	std::cout << Jhon;
	Jhon.signForm(formExample);
	Jhon.executeForm(formExample);
	std::cout << formExample;
}
void testBureaucratExecPresidentialPardonFormValidSigned(void)
{
	std::cout << "SIGNED FORM VALID EXEC" << std::endl;
	std::cout << "Bureaucrat Trying to execute a PresidentialPardonForm Signed with a ExecGrade smaller than the Bureaucrat one's" << std::endl;
	PresidentialPardonForm formExample = PresidentialPardonForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 137);
	std::cout << formExample;
	std::cout << Jhon;
	Jhon.signForm(formExample);
	Jhon.executeForm(formExample);
	std::cout << formExample;
}
void testBureaucratExecPresidentialPardonForm(void)
{
	tryCatch(testBureaucratExecPresidentialPardonFormInvalidNotSigned);
	tryCatch(testBureaucratExecPresidentialPardonFormInvalidSigned);
	tryCatch(testBureaucratExecPresidentialPardonFormValidNotSigned);
	tryCatch(testBureaucratExecPresidentialPardonFormValidSigned);
}
