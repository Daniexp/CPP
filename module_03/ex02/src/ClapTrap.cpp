/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:11:16 by dexposit          #+#    #+#             */
/*   Updated: 2023/03/31 18:56:16 by dexposit         ###   ########.fr       */
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

ClapTrap::ClapTrap(const std::string& Name): hit_pts(10), energy_pts(10), attack_dmg(0)
{
	std::cout << "Name Constructor Called." << std::endl;
	this->Name = Name;
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

std::ostream& operator<<(std::ostream& os, const ClapTrap& src)
{
	os << "Name: " << src.get_name() << ", hit pts: " << src.get_hitpts() << ", energy pts: " << src.get_energypts() << ", attack dmg: " << src.get_attackdmg();
	return os;
}

void ClapTrap::attack(std::string const& target)
{
	if (target == "" || this->hit_pts == 0 || this->energy_pts == 0)
		return ;
	std::cout << "ClapTrap " << this->Name << " attacks "  << target
		<< ", causing " << this->attack_dmg << " points of damage!" << std::endl;
		return ;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_pts == 0 || amount == 0)
		return ;
	this->hit_pts = (this->hit_pts > amount) ? this->hit_pts - amount : 0;
	std::cout << this->Name << " take damege of " << amount << " points." <<  std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_pts == 0)
		return ;
	this->energy_pts--;

	this->hit_pts += amount;
	if (this->hit_pts > 10)
		this->hit_pts = 10;
	std::cout << this->Name << " repaired himself " << amount << " points to 10." <<  std::endl;
}

std::string	ClapTrap::get_name(void) const
{
	return this->Name;
}
unsigned int ClapTrap::get_hitpts(void) const
{
	return this->hit_pts;
}
unsigned int ClapTrap::get_energypts(void) const
{
	return this->energy_pts;
}
unsigned int ClapTrap::get_attackdmg(void) const
{
	return this->attack_dmg;
}

void ClapTrap::set_name(const std::string& name)
{
	if (name != "")
		this->Name = name;
}
void			ClapTrap::set_hitpts(unsigned int amount)
{
		this->hit_pts = amount;
}
void			ClapTrap::set_energypts(unsigned int amount)
{
		this->energy_pts = amount;
}
void			ClapTrap::set_attackdmg(unsigned int amount)
{
	this->attack_dmg = amount;
}