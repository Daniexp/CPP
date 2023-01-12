#include <ex01.hpp>

class Contact
{
	std::string	firstname;
	std::string	lastname;
	std::string	nickname;
	std::string phonenumber;
	std::string	darkestsecret;
	public:
		Contact(std::string fst_nm, std::string lst_nm, std::string nick, std::string phn, std::string dks);
		Contact(void);
		~Contact(void);
		void	printData(void);
		std::string		truncateData(std::string data);
};
