#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <ex01.hpp>
class	PhoneBook
{
	Contact contacts[8];
	int		saved;
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void addContact(void);
		void searchContact(void);
		void printContactsData(void);
		std::string askContactData(std::string message, int phone);
};
#endif
