#include <ex01.hpp>

Contact::Contact(std::string fst_nm, std::string lst_nm, std::string nick, std::string phn, std::string dks)
{
	firstname = fst_nm;
	firstname.reserve(firstname.length());
	lastname = lst_nm;
	lastname.reserve(lastname.length());
	nickname = nick;
	nickname.reserve(nickname.length());
	phonenumber = phn;
	phonenumber.reserve(phonenumber.length());
	darkestsecret = dks;
	darkestsecret.reserve(darkestsecret.length());
};
Contact::Contact(void)
{
	std::cout << "Called the Contact Constructor" << std::endl;
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
	std::cout << std::setw(10) << truncateData(firstname) << "|" << std::setw(10) << truncateData(lastname) << "|" << std::setw(10) << truncateData(nickname) << "|" << std::setw(10) << truncateData(phonenumber) << "|" << std::setw(10) << truncateData(darkestsecret) << std::endl;
}
void	Contact::printData(void)
{
	std::cout << firstname << std::endl << lastname << std::endl << nickname << std::endl << phonenumber << std::endl << darkestsecret << std::endl;
}
