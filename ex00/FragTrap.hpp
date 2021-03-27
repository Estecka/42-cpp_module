/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 18:39:40 by abaur             #+#    #+#             */
/*   Updated: 2021/03/27 14:48:53 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>

class FragTrap
{
public:
	FragTrap(void);
	FragTrap& operator =(const FragTrap&);
	FragTrap(const FragTrap&);
	FragTrap(std::string name);
	~FragTrap();

	void	rangedAttack(std::string targetName);
	void	meleeAttack(std::string targetName);
	void	takeDamage(unsigned int	dmgAmount);
	void	beRepaired(unsigned int	healAmount);

	void	vaulthunter_dot_exe(std::string targetName);

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
