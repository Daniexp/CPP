#include <iostream>
#include <GradeTooLowException.hpp>
#include <GradeTooHighException.hpp>
#include <Form.hpp>
#include <Bureaucrat.hpp>
#include <string>
#include <test.hpp>

int main(void)
{
	int messageLength = 60;
	char fillchar = '-';

	testBureaucrat(messageLength, fillchar); 
	std::cout << std::endl << std::endl;

	testForm(messageLength, fillchar);

	return 0;
}
