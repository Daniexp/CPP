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
	std::cout << "The proyect was created sucessfully." << std::endl;
	Bureaucrat boss = Bureaucrat("Jefazo", 1);
	try
	{
		boss.incrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
	try
	{
		Form("bad", 0, 150);
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
	try
	{
		Form("bad", 150, 0);
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
	try
	{
		Form("bad", 151, 150);
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
	try
	{
		Form("bad", 150, 151);
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}

	Bureaucrat Pepe = Bureaucrat("Pepe", 20);
	Form ordinaryForm = Form("Ordinary", 150, 100);
	Form bossForm = Form("BossForm", 1, 1);
	try
	{
		bossForm.beSigned(Pepe);
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
	std::cout << boss << Pepe << ordinaryForm << bossForm;
	try
	{
		bossForm.beSigned(boss);
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
	try
	{
		ordinaryForm.beSigned(Pepe);
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
	std::cout << ordinaryForm << bossForm;
}
