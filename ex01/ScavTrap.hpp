/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 18:39:40 by abaur             #+#    #+#             */
/*   Updated: 2021/03/27 15:29:33 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>

class ScavTrap
{
public:
	ScavTrap(void);
	ScavTrap& operator =(const ScavTrap&);
	ScavTrap(const ScavTrap&);
	ScavTrap(std::string name);
	~ScavTrap();

	void	rangedAttack(std::string targetName);
	void	meleeAttack(std::string targetName);
	void	takeDamage(unsigned int	dmgAmount);
	void	beRepaired(unsigned int	healAmount);

	void	challengeNewcomer();

private:
	std::string	name;
	int	hitPoints;
	int	hitPointsMax;
	int	energyPoints;
	int	energyPointsMax;
	int	level;
	int	atkMelee;
	int	atkRanged;
	int	def;
};

#endif
