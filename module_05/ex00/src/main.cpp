#include <iostream>
#include <Bureaucrat.hpp>
#include <string>
#include <GradeTooLowExcept.hpp>
#include <GradeTooHighExcept.hpp>
#include <test.hpp>


int main(void)
{
	int messageLength = 60;
	char fillchar = '-';

	testBureaucrat(messageLength, fillchar);
	return 0;
}
