#ifndef TEST_HPP
#define TEST_HPP
#include <string>
#include <iostream>
#include <Bureaucrat.hpp>
#include <AForm.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>
//	TEST UTILS
void 	imprimirCentrado(const std::string& message, int maxlen, char fillchar); 
void	tryCatch(void (*testBureaucratFunction)(void));
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
void	testShrubberyCreationFormCreateInvalidSignGrade(void);
void	testShrubberyCreationFormCreateInvalidExecGrade(void);
void	testShrubberyCreationFormCreateInvalidGrade(void);
void	testShrubberyCreationFormGetters(void);
void	testShrubberyCreationFormBeSigned(void);
void	testBureaucratSignShrubberyCreationForm(void);
void	testShrubberyCreationForm(int messageLength, char fillchar);
#endif
