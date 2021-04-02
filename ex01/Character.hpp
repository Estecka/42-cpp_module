/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:19:29 by abaur             #+#    #+#             */
/*   Updated: 2021/04/02 15:36:33 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AWeapon.hpp"
#include "Enemy.hpp"

#include <iostream>

class Character
{
public:
	Character(void);
	Character(const Character&);
	Character(const std::string& name);
	~Character();
	Character&	operator =(const Character&);

	std::string	getName() const;
	int	getAP() const;
	int getAPMax() const;
	const AWeapon*	getWeapon() const;

	void	recoverAP();
	void	equip(AWeapon*);
	bool	attack(Enemy*);

private:
	std::string	name;
	int	actionPoints;
	int	actionPointsMax;
	AWeapon*	weapon;

	void	defaultInit(const std::string& name);
};

std::ostream&	operator <<(std::ostream& dst, const Character& src);

#endif