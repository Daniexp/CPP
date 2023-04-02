/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dexposit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:11:13 by dexposit          #+#    #+#             */
/*   Updated: 2023/04/02 18:23:40 by dexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H
# include <iostream>
# include <string>
# include <ex03.hpp>
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
	std::string get_name(void) const;
	unsigned int	get_hitpts() const;
	unsigned int	get_energypts() const;
	unsigned int	get_attackdmg() const;
	void			set_name(const std::string& name);
	void			set_hitpts(unsigned int amount);
	void			set_energypts(unsigned int amount);
	void			set_attackdmg(unsigned int amount);
	private:
	std::string		Name;
	unsigned int	hit_pts;
	unsigned int	energy_pts;
	unsigned int	attack_dmg;
	
};
std::ostream& operator<<(std::ostream& os, const ClapTrap& src);

#endif //CLAPTRAP_H


