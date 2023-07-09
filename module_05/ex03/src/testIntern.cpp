#include <test.hpp>

void	testIntern(AForm *formExample, int messageLength, char fillchar)
{
	imprimirCentrado("TEST SHRUBBERYCREATIONFORM", messageLength, fillchar);
	std::cout << std::endl;

//	testBureaucratSignIntern(formExample);

	testInternExecute(formExample);

	testBureaucratExecIntern(formExample);

	imprimirCentrado("END", messageLength, fillchar);
}
void	testInternGetters(AForm *applyIntern)
{
	std::cout << "Call getters" << std::endl;
	std::cout << applyIntern;
	std::cout << "Name : " << applyIntern->getName() << std::endl;
	std::cout << "IsSigned : " << applyIntern->getIsSigned() << std::endl;
	std::cout << "ExecGrade : " << applyIntern->getExecGrade() << std::endl;
	std::cout << "SignGrade : " << applyIntern->getSignGrade() << std::endl;
}
void	testInternBeSignedInvalid(AForm *formExample)
{
	std::cout << "Trying to sign a form with a SignGrade bigger than the Bureaucrat one's" << std::endl;
	Bureaucrat Jhon = Bureaucrat("Jhon", 146);
	std::cout << formExample;
	std::cout << Jhon;
	formExample->beSigned(Jhon);
	std::cout << formExample;
}
void	testInternBeSignedSigned(AForm *formExample)
{
	std::cout << "Trying to sign a form that is already signed." << std::endl;
	Bureaucrat Jhon = Bureaucrat("Jhon", 14);
	std::cout << formExample;
	std::cout << Jhon;
	Jhon.signForm(*formExample);
	std::cout << formExample;
	Jhon.signForm(*formExample);
	std::cout << formExample;
}
void	testInternBeSignedValid(AForm *formExample)
{
	std::cout << "Trying to sign a Intern with a SignGrade smaller than the Bureaucrat one's" << std::endl;
	Bureaucrat Jhon = Bureaucrat("Jhon", 143);
	std::cout << formExample;
	std::cout << Jhon;
	formExample->beSigned(Jhon);
	std::cout << formExample;
}
void	testInternBeSigned(AForm *formExample)
{
	tryCatch2(testInternBeSignedInvalid, formExample);
	tryCatch2(testInternBeSignedValid, formExample);
	tryCatch2(testInternBeSignedSigned, formExample);
}
void	testInternExecuteInvalidNotSigned(AForm *formExample)
{
	std::cout << "testInternExecuteInvalidNotSigned" << std::endl;
	std::cout << "UNSIGNED FORM INVALID EXEC" << std::endl;
	std::cout << "Trying to execute a Intern NotSigned with a ExecGrade bigger than the Bureaucrat one's" << std::endl;
	Bureaucrat Jhon = Bureaucrat("Jhon", 136);
	std::cout << formExample;
	std::cout << Jhon;
	formExample->execute(Jhon);
	std::cout << formExample;
}
void	testInternExecuteInvalidSigned(AForm *formExample)
{
	std::cout << "testInternExecuteInvalidSigned" << std::endl;
	std::cout << "SIGNED FORM INVALID EXEC" << std::endl;
	std::cout << "Trying to execute a Intern Signed with a ExecGrade bigger than the Bureaucrat one's" << std::endl;
	Bureaucrat Jhon = Bureaucrat("Jhon", 136);
	std::cout << formExample;
	std::cout << Jhon;
	formExample->beSigned(Jhon);
	formExample->execute(Jhon);
	std::cout << formExample;
}
void	testInternExecuteValidNotSigned(AForm *formExample)
{
	std::cout << "testInternExecuteValidNotSigned" << std::endl;
	std::cout << "UNSIGNED FORM VALID EXEC" << std::endl;
	std::cout << "Trying to execute a Intern NotSigned with a ExecGrade smaller than the Bureaucrat one's" << std::endl;
	Bureaucrat Jhon = Bureaucrat("Jhon", 137);
	std::cout << formExample;
	std::cout << Jhon;
	formExample->execute(Jhon);
	std::cout << formExample;
}
void	testInternExecuteValidSigned(AForm *formExample)
{
	std::cout << "testInternExecuteValidSigned" << std::endl;
	std::cout << "SIGNED FORM VALID EXEC" << std::endl;
	std::cout << "Trying to execute a Intern Signed with a ExecGrade smaller than the Bureaucrat one's" << std::endl;
	Bureaucrat Jhon = Bureaucrat("Jhon", 137);
	std::cout << formExample;
	std::cout << Jhon;
	Jhon.signForm(*formExample);
	Jhon.executeForm(*formExample);
	std::cout << formExample;
}
void	testInternExecute(AForm *formExample)
{
	tryCatch2(testInternExecuteInvalidNotSigned, formExample);
	tryCatch2(testInternExecuteInvalidSigned, formExample);
	tryCatch2(testInternExecuteValidNotSigned, formExample);
	tryCatch2(testInternExecuteValidSigned, formExample);
}
void testBureaucratExecInternInvalidNotSigned(AForm *formExample)
{
	std::cout << "UNSIGNED FORM INVALID EXEC" << std::endl;
	std::cout << "Bureaucrat Trying to execute a Intern NotSigned with a ExecGrade bigger than the Bureaucrat one's" << std::endl;
	Bureaucrat Jhon = Bureaucrat("Jhon", 138);
	std::cout << formExample;
	std::cout << Jhon;
	Jhon.executeForm(*formExample);
	std::cout << formExample;
}
void testBureaucratExecInternInvalidSigned(AForm *formExample)
{
	std::cout << "SIGNED FORM INVALID EXEC" << std::endl;
	std::cout << "Bureaucrat Trying to execute a Intern Signed with a ExecGrade bigger than the Bureaucrat one's" << std::endl;
	Bureaucrat Jhon = Bureaucrat("Jhon", 138);
	std::cout << formExample;
	std::cout << Jhon;
	Jhon.signForm(*formExample);
	Jhon.executeForm(*formExample);
	std::cout << formExample;
}
void testBureaucratExecInternValidNotSigned(AForm *formExample)
{
	std::cout << "NOT SIGNED FORM VALID EXEC" << std::endl;
	std::cout << "Bureaucrat Trying to execute a Intern NotSigned with a ExecGrade smaller than the Bureaucrat one's" << std::endl;
	Bureaucrat Jhon = Bureaucrat("Jhon", 137);
	std::cout << formExample;
	std::cout << Jhon;
	Jhon.executeForm(*formExample);
	std::cout << formExample;
}
void testBureaucratExecInternValidSigned(AForm *formExample)
{
	std::cout << "SIGNED FORM VALID EXEC" << std::endl;
	std::cout << "Bureaucrat Trying to execute a Intern Signed with a ExecGrade smaller than the Bureaucrat one's" << std::endl;
	Bureaucrat Jhon = Bureaucrat("Jhon", 137);
	std::cout << formExample;
	std::cout << Jhon;
	Jhon.signForm(*formExample);
	Jhon.executeForm(*formExample);
	std::cout << formExample;
}
void testBureaucratExecIntern(AForm *formExample)
{
	tryCatch2(testBureaucratExecInternInvalidNotSigned, formExample);
	tryCatch2(testBureaucratExecInternInvalidSigned, formExample);
	tryCatch2(testBureaucratExecInternValidNotSigned, formExample);
	tryCatch2(testBureaucratExecInternValidSigned, formExample);
}
