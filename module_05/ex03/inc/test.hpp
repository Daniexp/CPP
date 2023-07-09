#ifndef TEST_HPP
#define TEST_HPP
#include <string>
#include <iostream>
#include <Bureaucrat.hpp>
#include <AForm.hpp>
#include <Intern.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>
//	TEST UTILS
void 	imprimirCentrado(const std::string& message, int maxlen, char fillchar); 
void	tryCatch(void (*testBureaucratFunction)(void));
void	tryCatch2(void (*testBureaucratFunction)(AForm *), AForm * formExample);
//	TEST BUREAUCRAT	(ex00)
void	testBureaucratCreateInvalidGradeTooLow(void);
void	testBureaucratCreateInvalidGradeTooHigh(void);
void 	testBureaucratCreateInvalidGrade(void);
void 	testBureaucratChangeGrade(void);
void 	testBureaucratInvalidIncrement(void);
void	testBureaucratInvalidDecrement(void);
void	testBureaucratGeters(void);
void	testBureaucrat(int messageLength, char fillchar);
//	TEST FORM (ex01)
void	testAFormCreateInvalidSignGrade(void);
void	testAFormCreateInvalidExecGrade(void);
void	testAFormCreateInvalidGrade(void);
void	testAFormGetters(void);
void	testAFormBeSigned(void);
void	testBureaucratSignAForm(void);
void	testAForm(int messageLength, char fillchar);
//	TEST SHRUBERRYCREATIONFORM
void	testShrubberyCreationFormGetters(void);
void	testShrubberyCreationFormBeSigned(void);
void	testBureaucratSignShrubberyCreationForm(void);
void	testShrubberyCreationFormExecuteInvalidNotSigned(void);
void	testShrubberyCreationFormExecuteInvalidSigned(void);
void	testShrubberyCreationFormExecuteValidNotSigned(void);
void	testShrubberyCreationFormExecuteInvalidSigned(void);
void	testShrubberyCreationFormExecute(void);
void	testBureaucratExecShrubberyCreationFormInvalidNotSigned(void);
void	testBureaucratExecShrubberyCreationFormInvalidSigned(void);
void	testBureaucratExecShrubberyCreationFormValidNotSigned(void);
void	testBureaucratExecShrubberyCreationFormValidSigned(void);
void	testBureaucratExecShrubberyCreationForm(void);
void	testShrubberyCreationForm(int messageLength, char fillchar);
//	TEST ROBOTOMYREQUESTFORM
void	testRobotomyRequestFormGetters(void);
void	testRobotomyRequestFormBeSigned(void);
void	testBureaucratSignRobotomyRequestForm(void);
void	testRobotomyRequestFormExecuteInvalidNotSigned(void);
void	testRobotomyRequestFormExecuteInvalidSigned(void);
void	testRobotomyRequestFormExecuteValidNotSigned(void);
void	testRobotomyRequestFormExecuteInvalidSigned(void);
void	testRobotomyRequestFormExecute(void);
void	testBureaucratExecRobotomyRequestFormInvalidNotSigned(void);
void	testBureaucratExecRobotomyRequestFormInvalidSigned(void);
void	testBureaucratExecRobotomyRequestFormValidNotSigned(void);
void	testBureaucratExecRobotomyRequestFormValidSigned(void);
void	testBureaucratExecRobotomyRequestForm(void);
void	testRobotomyRequestForm(int messageLength, char fillchar);
//	TEST PRESIDENTIALPARDONFORM
void	testPresidentialPardonFormGetters(void);
void	testPresidentialPardonFormBeSigned(void);
void	testBureaucratSignPresidentialPardonForm(void);
void	testPresidentialPardonFormExecuteInvalidNotSigned(void);
void	testPresidentialPardonFormExecuteInvalidSigned(void);
void	testPresidentialPardonFormExecuteValidNotSigned(void);
void	testPresidentialPardonFormExecuteInvalidSigned(void);
void	testPresidentialPardonFormExecute(void);
void	testBureaucratExecPresidentialPardonFormInvalidNotSigned(void);
void	testBureaucratExecPresidentialPardonFormInvalidSigned(void);
void	testBureaucratExecPresidentialPardonFormValidNotSigned(void);
void	testBureaucratExecPresidentialPardonFormValidSigned(void);
void	testBureaucratExecPresidentialPardonForm(void);
void	testPresidentialPardonForm(int messageLength, char fillchar);
//	TEST INTERN
void	testInternGetters(AForm *formExample);
void	testInternBeSigned(AForm *formExample);
void	testBureaucratSignIntern(AForm *formExample);
void	testInternExecuteInvalidNotSigned(AForm *formExample);
void	testInternExecuteInvalidSigned(AForm *formExample);
void	testInternExecuteValidNotSigned(AForm *formExample);
void	testInternExecuteInvalidSigned(AForm *formExample);
void	testInternExecute(AForm *formExample);
void	testBureaucratExecInternInvalidNotSigned(AForm *formExample);
void	testBureaucratExecInternInvalidSigned(AForm *formExample);
void	testBureaucratExecInternValidNotSigned(AForm *formExample);
void	testBureaucratExecInternValidSigned(AForm *formExample);
void	testBureaucratExecIntern(AForm *formExample);
void	testIntern(AForm *formExample, int messageLength, char fillchar);
#endif
