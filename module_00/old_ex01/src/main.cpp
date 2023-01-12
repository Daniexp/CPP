/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:30:08 by dexposit          #+#    #+#             */
/*   Updated: 2022/08/15 15:18:15 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/useless_contacts.h"

int	main(void)
{
	CContact ejemplo;
	std::cout << "This is an example of a c program copiled.\n";
	std::cout << "This is an example of a c program copiled.\n";

	ejemplo.~CContact();
	CContact ej("hola", "mundo", "pwpw", 666, "prueba de una FRASe");
	ej.~CContact();
}
