/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:30:08 by dexposit          #+#    #+#             */
/*   Updated: 2022/08/14 16:47:11 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "useless_contacts.h"

int	main(void)
{
	CContact ejemplo;

	ejemplo.~CContact();
	CContact ej("hola", "mundo", "pwpw", 666, "prueba de una FRASe");
	ej.~CContact();
}
