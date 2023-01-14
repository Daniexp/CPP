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
		std::getline(std::cin, readline);
		readline.reserve(readline.length());
		if (phone == 1  && (!std::all_of(readline.begin(), readline.end(), ::isdigit) || readline.length() != 9))
			valid = false;
		else
			valid = true;
	}while (valid == false);
	return (readline);
}
void PhoneBook::addContact(void)
{
	std::string name = askContactData("Please enter the first name of the contact: ", 0);
	name.reserve(name.length());
	std::string last = askContactData("Please enter the last name of the contact: ", 0);
	last.reserve(last.length());
	std::string nick = askContactData("Please enter a nickname for the contact: ", 0);
	nick.reserve(nick.length());
	std::string phone = askContactData("Please enter the phone number of the contact without spaces: ", 1);
	phone.reserve(phone.length());
	std::string dark = askContactData("Please enter the darkest secret of the contact: ", 2);
	dark.reserve(dark.length());
		contacts[saved % 8] = Contact(name, last, nick, phone, dark);
	saved++;
	//if (saved > 8)
	//	saved = 0;
};
void PhoneBook::searchContact(void)
{
	int i = 0;
	for (i=0; i<9; i++)
	{
		if (i < saved)
		contacts[i].printDataTruncate();
	}
//	std::cout << "Please enter an index from 1 to 9, to print the Data of the Contact in the index row: ";
	std::cout << "Enter an index from 1 to 9 " << std::endl;
	int index=0;
	std::cin >> index;
	index--;
	if (index >= 0)
		contacts[index].printData();
};
void PhoneBook::printContactData(int index)
{
	if (index >= 0)
		contacts[index].printData();
};

