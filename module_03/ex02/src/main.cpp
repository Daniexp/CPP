/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:11:05 by dexposit          #+#    #+#             */
/*   Updated: 2023/04/10 14:15:32 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ex02.hpp>
# include <ClapTrap.hpp>
# include <ScavTrap.hpp>
# include <FragTrap.hpp>

int main(void)
{
    // Test ClapTrap
	ClapTrap clap("ClapTrap");
	std::cout << clap;
	clap.takeDamage(20);
	clap.beRepaired(10);
	clap.attack("Enemy");

    // Test ScavTrap
    ScavTrap scav("ScavTrap");
	std::cout << scav;
	scav.takeDamage(30);
 	scav.beRepaired(20);
 	scav.attack("Enemy");
    scav.guardGate();

    // Test FragTrap
	FragTrap frag("FragTrap");
	std::cout << frag;
	frag.takeDamage(40);
	frag.beRepaired(30);
	frag.attack("Enemy");
	frag.highFivesGuys();

	return 0;
}
