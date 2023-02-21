/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:11:13 by dexposit          #+#    #+#             */
/*   Updated: 2023/02/21 13:08:24 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H
# include <iostream>
# include <string>
:q
#include <ex00.hpp>
class	ClapTrap
{
	public:
	ClapTrap();
	~ClapTrap();
	ClapTrap(const ClapTrap& src);
	ClapTrap& operator=(const ClapTrap& src);
	void attack(std::string const& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	private:
	std::string		Name;
	unsigned int	hit_pts;
	unsigned int	energy_pts;
	unsigned int	attack_dmg;
	
};

#endif //CLAPTRAP_H


