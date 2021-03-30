/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 18:39:40 by abaur             #+#    #+#             */
/*   Updated: 2021/03/30 17:38:03 by abaur            ###   ########.fr       */
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

	void	rangedAttack(const std::string& targetName);
	void	meleeAttack(const std::string& targetName);
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
