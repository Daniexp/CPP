#include <test.hpp>

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
	std::cout << boss;
	std::cout << "Increment Max Grade" << std::endl;
	boss.incrementGrade();
	std::cout << boss;
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
	std::cout << "Call Bureaucrat geters" << std::endl;
	Bureaucrat Pepe = Bureaucrat("Pepe", 150);
	std::cout << Pepe;
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
