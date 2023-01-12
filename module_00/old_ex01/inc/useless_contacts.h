/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useless_contacts.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:28:01 by dexposit          #+#    #+#             */
/*   Updated: 2022/08/14 16:36:51 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef USELESS_CONTACTS_H
# define USELESS_CONTACTS_H
/*	C++ INCLUDES	*/
# include <iostream>
typedef std::basic_string<char>	string;

/*	CLASS PROTOTYPES	*/
class	CContact
{
	std::string	first_name;
	std::string	last_name;
	std::string	nick_name;
	int		phone;
	std::string	darkest_secret;
	public:
	CContact(std::string, std::string, std::string, int, std::string);
	CContact(void);
	~CContact(void);
	char	*get_first_name(void);
	char	*get_last_name(void);
	char	*get_nickname(void);
	int		*get_phone(void);
	char	*get_darkest_secret(void);
	void	set_first_name(char *first);
	void	set_last_name(char *last);
	void	set_nickname(char *nick);
	void	set_phone(int *phone);
	void	set_darkest_secret(char *secret);
};
#endif
