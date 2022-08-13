/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:34:51 by dexposit          #+#    #+#             */
/*   Updated: 2022/08/13 15:09:36 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctype.h>
  
// Main() function: where the execution of program begins
int main(int argc, char **argv)
{
	switch (argc)
	{
		case 1:
			std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		break;
		default:
			for(int i=1; argv[i]; i++)
				for(int j=0; argv[i][j]; j++)
					putchar(toupper(argv[i][j]));
				//std::cout << argv[1] << "\n";
	}
    return 0;
}
