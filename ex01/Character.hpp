/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:19:29 by abaur             #+#    #+#             */
/*   Updated: 2021/04/01 17:23:41 by abaur            ###   ########.fr       */
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
	Character(int hp, const std::string& type);
	~Character();
	Character&	operator =(const Character&);

	std::string	getName() const;

	void	recoverAP();
	void	equip(AWeapon*);
	void	attack(Enemy*);
};

#endif