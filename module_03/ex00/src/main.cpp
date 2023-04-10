/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:11:05 by dexposit          #+#    #+#             */
/*   Updated: 2023/04/10 14:02:42 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ClapTrap.hpp>
int main(void)
{
	std::cout << "The proyect was created sucessfully." << std::endl;
	ClapTrap ej = ClapTrap("Ejemplo");
	ClapTrap cp = ej;
	cp = ClapTrap(ej);
	ej.attack(cp.get_name());
	ej.takeDamage(5);
	ej.beRepaired(5);
}
