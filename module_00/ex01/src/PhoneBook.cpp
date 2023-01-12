#include <ex01.hpp>

PhoneBook::PhoneBook(void)
{
	std::cout << "PhoneBook Constructor void called." << std::endl;
	this->saved = 0;
}
PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook Destructor called." << std::endl;
};
std::string PhoneBook::askContactData(std::string message, int phone)
{
	std::string readline;
	bool valid;
	do{
		std::cout << message;
		std::cin >> readline;
		std::cout << readline.length();
		if (phone == 1  && (!std::all_of(readline.begin(), readline.end(), ::isdigit) || readline.length() != 9))
				//readline.find_first_not_of("0123456789") == std::string::npos)//(std::strspn(readline.c_str(), "0123456789") > 0))
			valid = false;
		else //if (phone && std::strspn(readline.c_str(), "0123456789") == 0 && readline.length() == 9)
			valid = true;
	}while (valid == false);//(readline.length() > 0 && (!phone || std::strspn(readline.c_str(), "0123456789")));
	return (readline);
}
void PhoneBook::addContact(void)
{
	int nmb = 0;
	std::string name = askContactData("Please enter the first name of the contact: ", 0);
	std::string last = askContactData("Please enter the last name of the contact: ", 0);
	std::string nick = askContactData("Please enter a nickname for the contact: ", 0);
	std::string phone = askContactData("Please enter the phone number of the contact: ", 1);
	std::string dark = askContactData("Please enter the darkest secret of the contact: ", 0);
	(this->contacts)[nmb] = Contact(name, last, nick, phone, dark);
};
void PhoneBook::searchContact(void)
{
};
void PhoneBook::printContactsData(void)
{
};

