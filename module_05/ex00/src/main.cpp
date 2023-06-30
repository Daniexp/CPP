#include <iostream>
#include <Bureaucrat.hpp>
#include <string>
#include <GradeTooLowExcept.hpp>
#include <GradeTooHighExcept.hpp>

void 	imprimirCentrado(const std::string& message, int maxlen, char fillchar); 
void	tryCatch(void (*testFunction)(void));

void	testCreateInvalidGradeTooLow(void)
{
	Bureaucrat Lowgrade = Bureaucrat("TooLow", 200);
}
void	testCreateInvalidGradeTooHigh(void)
{
	Bureaucrat Highgrade = Bureaucrat("TooHigh", -100);
}
void testCreateInvalidGrade(void)
{
	tryCatch(testCreateInvalidGradeTooLow);
	tryCatch(testCreateInvalidGradeTooHigh);
}
int main(void)
{
	Bureaucrat Pepe = Bureaucrat("Pepe", 150);
	std::cout << Pepe;
	Pepe.incrementGrade();
	std::cout << Pepe;
	testCreateInvalidGrade();

	return 0;
}

void	 imprimirCentrado(const std::string& message, int maxlen, char fillchar) {
    int messageLength = static_cast<int>(message.length());
    int padding = maxlen - messageLength;
	int leftPadding;
	int rightPadding;

    if (padding <= 0)
        std::cout << message << std::endl;
     else {
        leftPadding = padding / 2;
        rightPadding = padding - leftPadding;

        for (int i = 0; i < leftPadding; ++i)
            std::cout << fillchar;
        std::cout << message;

        for (int i = 0; i < rightPadding; ++i)
            std::cout << fillchar;

        std::cout << std::endl;
    }
}

void	tryCatch(void (*testFunction)(void))
{
	int messageLength = 60;
	char fillchar = '-';
	static int countTest = 1;
	

	imprimirCentrado("TEST 1" + std::to_string(countTest++), messageLength, fillchar); 
	imprimirCentrado("", messageLength, fillchar); 
	try
	{
		testFunction();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	imprimirCentrado("END", messageLength, fillchar); 
}
