#include <ex01.hpp>

Contact::Contact(std::string fst_nm, std::string lst_nm, std::string nick, std::string phn, std::string dks)
{
	firstname = fst_nm;
	lastname = lst_nm;
	nickname = nick;
	phonenumber = phn;
	darkestsecret = dks;
};
Contact::Contact(void)
{
	std::cout << "Called the Contact Constructor" << std::endl;
	firstname = "";
	lastname = "";
	nickname = "";
	phonenumber = "";
	darkestsecret = "";
}
Contact::~Contact(void)
{
	std::cout << "Called Destructor of the class Contact." << std::endl;
};
std::string	Contact::truncateData(std::string data)
{
	if (data.length() <= 10)
		return (data);
	data = data.substr(0, 10);
	data.replace(data.length()-1, 1, ".");
	return (data);
}
void	Contact::printDataTruncate(void)
{
	std::cout << std::setw(10) << truncateData(this->firstname) << "|" << std::setw(10) << truncateData(this->lastname) << "|" << std::setw(10) << truncateData(this->nickname) << "|" << std::setw(10) << truncateData(this->phonenumber) << "|" << std::setw(10) << truncateData(this->darkestsecret) << std::endl;
}
void	Contact::printData(void)
{
	std::cout << firstname << std::endl << lastname << std::endl << nickname << std::endl << phonenumber << std::endl << darkestsecret << std::endl;
}
