/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:11:16 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/21 13:08:42 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ClapTrap.hpp>
 
ClapTrap::ClapTrap(): Name(""), hit_pts(10), energy_pts(10), attack_dmg(0)
{
//Const
	std::cout << "Default Constructor /ClapTrap" << std::endl;
}
 
ClapTrap::~ClapTrap()
{
//Dest
	std::cout << "Destructor /ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	std::cout << "Copy Constructor /ClapTrap" << std::endl;
	*this = src;
}

ClapTrap& ClapTrap::operator = (const ClapTrap& src)
{
	std::cout << "Asignation operator = /ClapTrap" << std::endl;
	this->Name = src.Name;
	this->hit_pts = src.hit_pts;
	this->energy_pts = src.energy_pts;
	this->attack_dmg = src.attack_dmg;
	return *this;
}

void ClapTrap::attack(std::string const& target)
{
	if (!target)
		return ;
	std::cout << "Attack" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
}

void ClapTrap::beRepaired(unsigned int amount)
{
}
