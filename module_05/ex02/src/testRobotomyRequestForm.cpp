#include <test.hpp>

void	testRobotomyRequestFormBeSignedSigned(void)
{
	std::cout << "Trying to sign a RobotomyRequestForm that is already signed." << std::endl;
	RobotomyRequestForm formExample = RobotomyRequestForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 14);
	std::cout << formExample;
	std::cout << Jhon;
	formExample.beSigned(Jhon);
	std::cout << formExample;
	formExample.beSigned(Jhon);
	std::cout << formExample;
}
void	testBureaucratSignRobotomyRequestFormSigned(void)
{
	std::cout << "Bureaucrat trying to sign a RobotomyRequestForm that is already signed." << std::endl;
	RobotomyRequestForm formExample = RobotomyRequestForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 14);
	std::cout << formExample;
	std::cout << Jhon;
	Jhon.signForm(formExample);
	std::cout << formExample;
	Jhon.signForm(formExample);
	std::cout << formExample;
}
void	testRobotomyRequestForm(int messageLength, char fillchar)
{
	imprimirCentrado("TEST ROBOTOMYREQUESTFORM", messageLength, fillchar);
	std::cout << std::endl;

	tryCatch(testRobotomyRequestFormGetters);

	testRobotomyRequestFormBeSigned();

	testBureaucratSignRobotomyRequestForm();

	testRobotomyRequestFormExecute();

	testBureaucratExecRobotomyRequestForm();

	imprimirCentrado("END", messageLength, fillchar);
}
void	testRobotomyRequestFormGetters(void)
{
	std::cout << "Call RobotomyRequestForm getters" << std::endl;
	RobotomyRequestForm applyRobotomyRequestForm = RobotomyRequestForm("Applyform");
	std::cout << applyRobotomyRequestForm;
	std::cout << "Name : " << applyRobotomyRequestForm.getName() << std::endl;
	std::cout << "IsSigned : " << applyRobotomyRequestForm.getIsSigned() << std::endl;
	std::cout << "ExecGrade : " << applyRobotomyRequestForm.getExecGrade() << std::endl;
	std::cout << "SignGrade : " << applyRobotomyRequestForm.getSignGrade() << std::endl;
}
void	testRobotomyRequestFormBeSignedInvalid(void)
{
	std::cout << "Trying to sign a RobotomyRequestForm with a ExecGrade bigger than the Bureaucrat one's" << std::endl;
	RobotomyRequestForm formExample = RobotomyRequestForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 73);
	std::cout << formExample;
	std::cout << Jhon;
	formExample.beSigned(Jhon);
	std::cout << formExample;
}
void	testRobotomyRequestFormBeSignedValid(void)
{
	std::cout << "Trying to sign a RobotomyRequestForm with a ExecGrade smaller than the Bureaucrat one's" << std::endl;
	RobotomyRequestForm formExample = RobotomyRequestForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 72);
	std::cout << formExample;
	std::cout << Jhon;
	formExample.beSigned(Jhon);
	std::cout << formExample;
}
void	testRobotomyRequestFormBeSigned(void)
{
	tryCatch(testRobotomyRequestFormBeSignedInvalid);
	tryCatch(testRobotomyRequestFormBeSignedValid);
	tryCatch(testRobotomyRequestFormBeSignedSigned);
}
void	testBureaucratSignRobotomyRequestFormInvalid(void)
{
	std::cout << "Bureaucrat trying to sign a RobotomyRequestForm with less signGrade than the require one" << std::endl;
	RobotomyRequestForm formExample = RobotomyRequestForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 73);
	std::cout << formExample;
	std::cout << Jhon;
	Jhon.signForm(formExample);
	std::cout << formExample;
}
void	testBureaucratSignRobotomyRequestFormValid(void)
{
	std::cout << "Bureaucrat trying to sign a RobotomyRequestForm with more signGrade than the require one" << std::endl;
	RobotomyRequestForm formExample = RobotomyRequestForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 72);
	std::cout << formExample;
	std::cout << Jhon;
	Jhon.signForm(formExample);
	std::cout << formExample;
}
void	testBureaucratSignRobotomyRequestForm(void)
{
	tryCatch(testBureaucratSignRobotomyRequestFormInvalid);
	tryCatch(testBureaucratSignRobotomyRequestFormValid);
}
void	testRobotomyRequestFormExecuteInvalidNotSigned(void)
{
	std::cout << "UNSIGNED FORM INVALID EXEC" << std::endl;
	std::cout << "Trying to execute a RobotomyRequestForm NotSigned with a ExecGrade bigger than the Bureaucrat one's" << std::endl;
	RobotomyRequestForm formExample = RobotomyRequestForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 46);
	std::cout << formExample;
	std::cout << Jhon;
	formExample.execute(Jhon);
	std::cout << formExample;
}
void	testRobotomyRequestFormExecuteInvalidSigned(void)
{
	std::cout << "SIGNED FORM INVALID EXEC" << std::endl;
	std::cout << "Trying to execute a RobotomyRequestForm Signed with a ExecGrade bigger than the Bureaucrat one's" << std::endl;
	RobotomyRequestForm formExample = RobotomyRequestForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 46);
	std::cout << formExample;
	std::cout << Jhon;
	formExample.beSigned(Jhon);
	formExample.execute(Jhon);
	std::cout << formExample;
}
void	testRobotomyRequestFormExecuteValidNotSigned(void)
{
	std::cout << "UNSIGNED FORM VALID EXEC" << std::endl;
	std::cout << "Trying to execute a RobotomyRequestForm NotSigned with a ExecGrade smaller than the Bureaucrat one's" << std::endl;
	RobotomyRequestForm formExample = RobotomyRequestForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 45);
	std::cout << formExample;
	std::cout << Jhon;
	formExample.execute(Jhon);
	std::cout << formExample;
}
void	testRobotomyRequestFormExecuteValidSigned(void)
{
	std::cout << "SIGNED FORM VALID EXEC" << std::endl;
	std::cout << "Trying to execute a RobotomyRequestForm Signed with a ExecGrade smaller than the Bureaucrat one's" << std::endl;
	RobotomyRequestForm formExample = RobotomyRequestForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 45);
	std::cout << formExample;
	std::cout << Jhon;
	formExample.beSigned(Jhon);
	formExample.execute(Jhon);
	std::cout << formExample;
}
void	testRobotomyRequestFormExecute(void)
{
	tryCatch(testRobotomyRequestFormExecuteInvalidNotSigned);
	tryCatch(testRobotomyRequestFormExecuteInvalidSigned);
	tryCatch(testRobotomyRequestFormExecuteValidNotSigned);
	tryCatch(testRobotomyRequestFormExecuteValidSigned);
}
void testBureaucratExecRobotomyRequestFormInvalidNotSigned(void)
{
	std::cout << "UNSIGNED FORM INVALID EXEC" << std::endl;
	std::cout << "Bureaucrat Trying to execute a RobotomyRequestForm NotSigned with a ExecGrade bigger than the Bureaucrat one's" << std::endl;
	RobotomyRequestForm formExample = RobotomyRequestForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 46);
	std::cout << formExample;
	std::cout << Jhon;
	Jhon.executeForm(formExample);
	std::cout << formExample;
}
void testBureaucratExecRobotomyRequestFormInvalidSigned(void)
{
	std::cout << "SIGNED FORM INVALID EXEC" << std::endl;
	std::cout << "Bureaucrat Trying to execute a RobotomyRequestForm Signed with a ExecGrade bigger than the Bureaucrat one's" << std::endl;
	RobotomyRequestForm formExample = RobotomyRequestForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 46);
	std::cout << formExample;
	std::cout << Jhon;
	Jhon.signForm(formExample);
	Jhon.executeForm(formExample);
	std::cout << formExample;
}
void testBureaucratExecRobotomyRequestFormValidNotSigned(void)
{
	std::cout << "NOT SIGNED FORM VALID EXEC" << std::endl;
	std::cout << "Bureaucrat Trying to execute a RobotomyRequestForm NotSigned with a ExecGrade smaller than the Bureaucrat one's" << std::endl;
	RobotomyRequestForm formExample = RobotomyRequestForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 45);
	std::cout << formExample;
	std::cout << Jhon;
	Jhon.executeForm(formExample);
	std::cout << formExample;
}
void testBureaucratExecRobotomyRequestFormValidSigned(void)
{
	std::cout << "SIGNED FORM VALID EXEC" << std::endl;
	std::cout << "Bureaucrat Trying to execute a RobotomyRequestForm Signed with a ExecGrade smaller than the Bureaucrat one's" << std::endl;
	RobotomyRequestForm formExample = RobotomyRequestForm("example");
	Bureaucrat Jhon = Bureaucrat("Jhon", 45);
	std::cout << formExample;
	std::cout << Jhon;
	Jhon.signForm(formExample);
	Jhon.executeForm(formExample);
	std::cout << formExample;
}
void testBureaucratExecRobotomyRequestForm(void)
{
	tryCatch(testBureaucratExecRobotomyRequestFormInvalidNotSigned);
	tryCatch(testBureaucratExecRobotomyRequestFormInvalidSigned);
	tryCatch(testBureaucratExecRobotomyRequestFormValidNotSigned);
	tryCatch(testBureaucratExecRobotomyRequestFormValidSigned);
}
