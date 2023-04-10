/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:11:13 by dexposit          #+#    #+#             */
/*   Updated: 2023/04/10 14:03:45 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H
#include <iostream>
#include <string>
class	ClapTrap
{
	public:
	ClapTrap();
	~ClapTrap();
	ClapTrap(const ClapTrap& src);
	ClapTrap(const std::string& Name);
	ClapTrap& operator=(const ClapTrap& src);
	void attack(std::string const& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::string get_name(void);
	private:
	std::string		Name;
	unsigned int	hit_pts;
	unsigned int	energy_pts;
	unsigned int	attack_dmg;
	
};

#endif //CLAPTRAP_H


