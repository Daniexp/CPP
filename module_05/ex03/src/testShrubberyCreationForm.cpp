#include <test.hpp>

void	testShrubberyCreationForm(int messageLength, char fillchar)
{
	imprimirCentrado("TEST SHRUBBERYCREATIONFORM", messageLength, fillchar);
	std::cout << std::endl;

	tryCatch(testShrubberyCreationFormGetters);

	//testShrubberyCreationFormBeSigned();

	testBureaucratSignShrubberyCreationForm();

	testShrubberyCreationFormExecute();

	testBureaucratExecShrubberyCreationForm();

	imprimirCentrado("END", messageLength, fillchar);
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
void	testShrubberyCreationFormBeSignedInvalid(void)
{
	std::cout << "Trying to sign a ShrubberyCreationForm with a SignGrade bigger than the Bureaucrat one's" << std::endl;
	ShrubberyCreationForm formExample = ShrubberyCreationForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 146);
	std::cout << formExample;
	std::cout << Jhon;
	formExample.beSigned(Jhon);
	std::cout << formExample;
}
void	testShrubberyCreationFormBeSignedSigned(void)
{
	std::cout << "Trying to sign a ShrubberyCreationForm that is already signed." << std::endl;
	ShrubberyCreationForm formExample = ShrubberyCreationForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 14);
	std::cout << formExample;
	std::cout << Jhon;
	formExample.beSigned(Jhon);
	std::cout << formExample;
	formExample.beSigned(Jhon);
	std::cout << formExample;
}
void	testShrubberyCreationFormBeSignedValid(void)
{
	std::cout << "Trying to sign a ShrubberyCreationForm with a SignGrade smaller than the Bureaucrat one's" << std::endl;
	ShrubberyCreationForm formExample = ShrubberyCreationForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 143);
	std::cout << formExample;
	std::cout << Jhon;
	formExample.beSigned(Jhon);
	std::cout << formExample;
}
void	testShrubberyCreationFormBeSigned(void)
{
	tryCatch(testShrubberyCreationFormBeSignedInvalid);
	tryCatch(testShrubberyCreationFormBeSignedValid);
	tryCatch(testShrubberyCreationFormBeSignedSigned);
}
void	testBureaucratSignShrubberyCreationFormInvalid(void)
{
	std::cout << "testBureaucratSignShrubberyCreationFormInvalid" << std::endl;
	std::cout << "Bureaucrat trying to sign a ShrubberyCreationForm with less signGrade than the require one" << std::endl;
	ShrubberyCreationForm formExample = ShrubberyCreationForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 146);
	std::cout << formExample;
	std::cout << Jhon;
	Jhon.signForm(formExample);
	std::cout << formExample;
}
void	testBureaucratSignShrubberyCreationFormValid(void)
{
	std::cout << "testBureaucratSignShrubberyCreationFormValid" << std::endl;
	std::cout << "Bureaucrat trying to sign a ShrubberyCreationForm with more signGrade than the require one" << std::endl;
	ShrubberyCreationForm formExample = ShrubberyCreationForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 143);
	std::cout << formExample;
	std::cout << Jhon;
	Jhon.signForm(formExample);
	std::cout << formExample;
}
void	testBureaucratSignShrubberyCreationFormSigned(void)
{
	std::cout << "Bureaucrat trying to sign a ShrubberyCreationForm that is already signed." << std::endl;
	ShrubberyCreationForm formExample = ShrubberyCreationForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 14);
	std::cout << formExample;
	std::cout << Jhon;
	Jhon.signForm(formExample);
	std::cout << formExample;
	Jhon.signForm(formExample);
	std::cout << formExample;
}
void	testBureaucratSignShrubberyCreationForm(void)
{
	tryCatch(testBureaucratSignShrubberyCreationFormInvalid);
	tryCatch(testBureaucratSignShrubberyCreationFormValid);
	tryCatch(testBureaucratSignShrubberyCreationFormSigned);
}
void	testShrubberyCreationFormExecuteInvalidNotSigned(void)
{
	std::cout << "testShrubberyCreationFormExecuteInvalidNotSigned" << std::endl;
	std::cout << "UNSIGNED FORM INVALID EXEC" << std::endl;
	std::cout << "Trying to execute a ShrubberyCreationForm NotSigned with a ExecGrade bigger than the Bureaucrat one's" << std::endl;
	ShrubberyCreationForm formExample = ShrubberyCreationForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 136);
	std::cout << formExample;
	std::cout << Jhon;
	formExample.execute(Jhon);
	std::cout << formExample;
}
void	testShrubberyCreationFormExecuteInvalidSigned(void)
{
	std::cout << "testShrubberyCreationFormExecuteInvalidSigned" << std::endl;
	std::cout << "SIGNED FORM INVALID EXEC" << std::endl;
	std::cout << "Trying to execute a ShrubberyCreationForm Signed with a ExecGrade bigger than the Bureaucrat one's" << std::endl;
	ShrubberyCreationForm formExample = ShrubberyCreationForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 136);
	std::cout << formExample;
	std::cout << Jhon;
	formExample.beSigned(Jhon);
	formExample.execute(Jhon);
	std::cout << formExample;
}
void	testShrubberyCreationFormExecuteValidNotSigned(void)
{
	std::cout << "testShrubberyCreationFormExecuteValidNotSigned" << std::endl;
	std::cout << "UNSIGNED FORM VALID EXEC" << std::endl;
	std::cout << "Trying to execute a ShrubberyCreationForm NotSigned with a ExecGrade smaller than the Bureaucrat one's" << std::endl;
	ShrubberyCreationForm formExample = ShrubberyCreationForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 137);
	std::cout << formExample;
	std::cout << Jhon;
	formExample.execute(Jhon);
	std::cout << formExample;
}
void	testShrubberyCreationFormExecuteValidSigned(void)
{
	std::cout << "testShrubberyCreationFormExecuteValidSigned" << std::endl;
	std::cout << "SIGNED FORM VALID EXEC" << std::endl;
	std::cout << "Trying to execute a ShrubberyCreationForm Signed with a ExecGrade smaller than the Bureaucrat one's" << std::endl;
	ShrubberyCreationForm formExample = ShrubberyCreationForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 137);
	std::cout << formExample;
	std::cout << Jhon;
	formExample.beSigned(Jhon);
	formExample.execute(Jhon);
	std::cout << formExample;
}
void	testShrubberyCreationFormExecute(void)
{
	tryCatch(testShrubberyCreationFormExecuteInvalidNotSigned);
	tryCatch(testShrubberyCreationFormExecuteInvalidSigned);
	tryCatch(testShrubberyCreationFormExecuteValidNotSigned);
	tryCatch(testShrubberyCreationFormExecuteValidSigned);
}
void testBureaucratExecShrubberyCreationFormInvalidNotSigned(void)
{
	std::cout << "UNSIGNED FORM INVALID EXEC" << std::endl;
	std::cout << "Bureaucrat Trying to execute a ShrubberyCreationForm NotSigned with a ExecGrade bigger than the Bureaucrat one's" << std::endl;
	ShrubberyCreationForm formExample = ShrubberyCreationForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 138);
	std::cout << formExample;
	std::cout << Jhon;
	Jhon.executeForm(formExample);
	std::cout << formExample;
}
void testBureaucratExecShrubberyCreationFormInvalidSigned(void)
{
	std::cout << "SIGNED FORM INVALID EXEC" << std::endl;
	std::cout << "Bureaucrat Trying to execute a ShrubberyCreationForm Signed with a ExecGrade bigger than the Bureaucrat one's" << std::endl;
	ShrubberyCreationForm formExample = ShrubberyCreationForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 138);
	std::cout << formExample;
	std::cout << Jhon;
	Jhon.signForm(formExample);
	Jhon.executeForm(formExample);
	std::cout << formExample;
}
void testBureaucratExecShrubberyCreationFormValidNotSigned(void)
{
	std::cout << "NOT SIGNED FORM VALID EXEC" << std::endl;
	std::cout << "Bureaucrat Trying to execute a ShrubberyCreationForm NotSigned with a ExecGrade smaller than the Bureaucrat one's" << std::endl;
	ShrubberyCreationForm formExample = ShrubberyCreationForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 137);
	std::cout << formExample;
	std::cout << Jhon;
	Jhon.executeForm(formExample);
	std::cout << formExample;
}
void testBureaucratExecShrubberyCreationFormValidSigned(void)
{
	std::cout << "SIGNED FORM VALID EXEC" << std::endl;
	std::cout << "Bureaucrat Trying to execute a ShrubberyCreationForm Signed with a ExecGrade smaller than the Bureaucrat one's" << std::endl;
	ShrubberyCreationForm formExample = ShrubberyCreationForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 137);
	std::cout << formExample;
	std::cout << Jhon;
	Jhon.signForm(formExample);
	Jhon.executeForm(formExample);
	std::cout << formExample;
}
void testBureaucratExecShrubberyCreationForm(void)
{
	tryCatch(testBureaucratExecShrubberyCreationFormInvalidNotSigned);
	tryCatch(testBureaucratExecShrubberyCreationFormInvalidSigned);
	tryCatch(testBureaucratExecShrubberyCreationFormValidNotSigned);
	tryCatch(testBureaucratExecShrubberyCreationFormValidSigned);
}
