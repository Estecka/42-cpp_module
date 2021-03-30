/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 19:23:42 by abaur             #+#    #+#             */
/*   Updated: 2021/03/30 17:47:35 by abaur            ###   ########.fr       */
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
	virtual ~ClapTrap();

	void	rangedAttack(const std::string& targetName);
	void	meleeAttack(const std::string& targetName);
	void	takeDamage(unsigned int	dmgAmount);
	void	beRepaired(unsigned int	healAmount);

	std::string	getName() const;
	void	showStats() const;

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


	virtual void	msgMelee(std::string targetName) const;
	virtual void	msgRanged(std::string targetName) const;
	virtual void	msgDamage(unsigned amount) const;
	virtual void	msgNoDamage() const;
	virtual void	msgAlreadyDead() const;
	virtual void	msgHeal(unsigned amount) const;
	virtual void	msgFullHealth() const;
	virtual void	msgNoEnergy() const;
	virtual void	msgNoHealth() const;

private:
	void	msgDefaultConstructor(void) const;
	void	msgCopyConstructor(const ClapTrap& original) const;
	void	msgNamedConstructor(std::string name) const;
	void	msgDestructor() const;
};

#endif