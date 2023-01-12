/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useless_contacts.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:22:48 by dexposit          #+#    #+#             */
/*   Updated: 2022/08/15 13:56:15 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/useless_contacts.h"

/*	CLASS CCONTACT DEFINITION	*/

CContact::CContact(std::string first, std::string last, std::string nick, int number, std::string secret)
{
	first_name = first;
	last_name = last;
	nick_name = nick;
	phone = number;
	darkest_secret = secret;	
}

CContact::CContact(void)
{
	first_name = "";
	last_name = ""; 
	nick_name = "";
	phone = 0;
	darkest_secret = "";
}
CContact::~CContact(void)
{
	first_name.~string();
	last_name.~string();
	nick_name.~string();
	darkest_secret.~string();
}
