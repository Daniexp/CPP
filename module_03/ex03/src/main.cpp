/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:11:05 by dexposit          #+#    #+#             */
/*   Updated: 2023/04/02 19:15:35 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ex03.hpp>
# include <ClapTrap.hpp>
# include <ScavTrap.hpp>
# include <FragTrap.hpp>
# include <DiamondTrap.hpp>

int main(void)
{
	std::cout << "Creating a ClapTrap..." << std::endl;
    ClapTrap clap("CL4P-TP");
    std::cout << clap << std::endl;

    std::cout << "Creating a FragTrap..." << std::endl;
    FragTrap frag("FR4G-TP");
    std::cout << frag << std::endl;

    std::cout << "Creating a ScavTrap..." << std::endl;
    ScavTrap scav("SC4V-TP");
    std::cout << scav << std::endl;

    std::cout << "Creating a DiamondTrap..." << std::endl;
    DiamondTrap diamond("DI4M0ND-TP");
    std::cout << diamond << std::endl;

    std::cout << "DiamondTrap attack ScavTrap..." << std::endl;
    diamond.attack("SC4V-TP");
    std::cout << std::endl;

    std::cout << "DiamondTrap use whoAmI() function..." << std::endl;
    diamond.whoAmI();

    DiamondTrap diamondTrap("Diamond");

    diamondTrap.whoAmI();

    diamondTrap.attack("enemy");

    diamondTrap.guardGate();

    DiamondTrap diamondTrapCopy(diamondTrap);

	std::cout << diamondTrap << std::endl;

    diamondTrapCopy.set_name("DiamondCopy");
    diamondTrapCopy.whoAmI();
    diamondTrapCopy.takeDamage(50);
    diamondTrapCopy.beRepaired(20);
}
