#include <ex01.hpp>
int main(void)
{
	PhoneBook agenda;
	std::string line;
	do{
		std::getline(std::cin, line);
		if (line == "ADD")
			agenda.addContact();
		if (line == "SEARCH")
			agenda.searchContact();
	}while (line != "EXIT");
}
