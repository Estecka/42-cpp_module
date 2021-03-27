/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 19:23:42 by abaur             #+#    #+#             */
/*   Updated: 2021/03/27 19:33:46 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
public:
	ClapTrap(void);
	ClapTrap& operator =(const ClapTrap&);
	ClapTrap(const ClapTrap&);
	ClapTrap(std::string name);
	~ClapTrap();

	void	rangedAttack(std::string targetName);
	void	meleeAttack(std::string targetName);
	void	takeDamage(unsigned int	dmgAmount);
	void	beRepaired(unsigned int	healAmount);

protected:
	std::string	name;
	int	hitPoints;
	int	hitPointsMax;
	int	energyPoints;
	int	energyPointsMax;
	int	level;
	int	atkMelee;
	int	atkRanged;
	int	def;

	virtual void	defaultInit(void);

	virtual std::string	msgMelee(std::string targetName) const;
	virtual std::string	msgRanged(std::string targetName) const;
	virtual std::string	msgDamage(unsigned amount) const;
	virtual std::string	msgNoDamage(unsigned amount) const;
	virtual std::string	msgAlreadyDead() const;
	virtual std::string	msgHeal(unsigned amount) const;
	virtual std::string	msgFullHealth() const;
	virtual std::string	msgNoEnergy() const;
};


#endif