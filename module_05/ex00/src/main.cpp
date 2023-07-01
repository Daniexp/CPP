#include <iostream>
#include <Bureaucrat.hpp>
#include <string>
#include <GradeTooLowExcept.hpp>
#include <GradeTooHighExcept.hpp>

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

void	testBureaucratCreateInvalidGradeTooLow(void)
{

	std::cout << "Trying to create a Bureaucrat with 200 of grade." << std::endl;
	Bureaucrat Lowgrade = Bureaucrat("TooLow", 200);
	std::cout << Lowgrade << std::endl;
}
void	testBureaucratCreateInvalidGradeTooHigh(void)
{
	std::cout << "Trying to create a Bureaucrat with -100 of grade." << std::endl;
	Bureaucrat Highgrade = Bureaucrat("TooHigh", -100);
	std::cout << Highgrade << std::endl;
}
void testBureaucratCreateInvalidGrade(void)
{
	tryCatch(testBureaucratCreateInvalidGradeTooLow);
	tryCatch(testBureaucratCreateInvalidGradeTooHigh);
}
void testBureaucratValidDecrement(void)
{
	Bureaucrat boss = Bureaucrat("Ayose", 1);
	std::cout << boss;
	std::cout << "Decrement Grade" << std::endl;
	boss.decrementGrade();
	std::cout << boss;
}
void testBureaucratValidIncrement(void)
{
	Bureaucrat boss = Bureaucrat("Ayose", 10);
	std::cout << boss;
	std::cout << "Increment Grade" << std::endl;
	boss.incrementGrade();
	std::cout << boss;
}
void testBureaucratInvalidIncrement()
{
	Bureaucrat boss = Bureaucrat("Ayose", 1);
	std::cout << boss << std::endl;
	std::cout << "Increment Max Grade" << std::endl;
	boss.incrementGrade();
	std::cout << boss << std::endl;
}
void testBureaucratInvalidDecrement()
{
	Bureaucrat boss = Bureaucrat("Ayose", 150);
	std::cout << boss;
	std::cout << "Decrement Min Grade" << std::endl;
	boss.decrementGrade();
	std::cout << boss;
}
void testBureaucratChangeGrade(void)
{
	tryCatch(testBureaucratValidDecrement);
	tryCatch(testBureaucratValidIncrement);
	tryCatch(testBureaucratInvalidDecrement);
	tryCatch(testBureaucratInvalidIncrement);
}
void	testBureaucratGeters()
{
	Bureaucrat Pepe = Bureaucrat("Pepe", 150);
	std::cout << "Name: " << Pepe.getName() << std::endl;
	std::cout << "Grade: " <<  Pepe.getGrade() << std::endl; 
}
void	testBureaucrat(int messageLength, char fillchar)
{
	imprimirCentrado("TEST BUREAUCRAT", messageLength, fillchar); 
	std::cout << std::endl;

	testBureaucratCreateInvalidGrade();

	tryCatch(testBureaucratGeters);

	testBureaucratChangeGrade();

	imprimirCentrado("END", messageLength, fillchar); 
}
int main(void)
{
	int messageLength = 60;
	char fillchar = '-';

	testBureaucrat(messageLength, fillchar);
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

void	tryCatch(void (*testBureaucratFunction)(void))
{
	int messageLength = 60;
	char fillchar = '-';
	static int countTest = 0;
	

	imprimirCentrado("TEST " + std::to_string(countTest++), messageLength, fillchar); 
	try
	{
		testBureaucratFunction();
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
}
