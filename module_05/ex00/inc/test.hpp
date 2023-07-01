#ifndef TEST_HPP
#define TEST_HPP
#include <string>
#include <iostream>
#include <Bureaucrat.hpp>
//	TEST UTILS
void 	imprimirCentrado(const std::string& message, int maxlen, char fillchar); 
void	tryCatch(void (*testBureaucratFunction)(void));
//	TEST BUREAUCRAT
void	testBureaucratCreateInvalidGradeTooLow(void);
void	testBureaucratCreateInvalidGradeTooHigh(void);
void 	testBureaucratCreateInvalidGrade(void);
void 	testBureaucratChangeGrade(void);
void 	testBureaucratInvalidIncrement(void);
void	testBureaucratInvalidDecrement(void);
void	testBureaucratGeters(void);
void	testBureaucrat(int messageLength, char fillchar);
#endif
