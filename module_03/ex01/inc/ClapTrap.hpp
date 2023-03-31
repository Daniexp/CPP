/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:11:13 by dexposit          #+#    #+#             */
/*   Updated: 2023/03/31 19:34:36 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H
# include <iostream>
# include <string>
# include <ex01.hpp>
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
	unsigned int	get_hitpts();
	unsigned int	get_energypts();
	unsigned int	get_attackdmg();
	private:
	std::string		Name;
	unsigned int	hit_pts;
	unsigned int	energy_pts;
	unsigned int	attack_dmg;
	
};

#endif //CLAPTRAP_H


