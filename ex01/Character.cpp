/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:11:16 by abaur             #+#    #+#             */
/*   Updated: 2021/04/02 14:35:54 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

void	Character::defaultInit(const std::string& name){
	this->name = name;
	this->actionPoints = 40;
	this->actionPointsMax = 40;
	this->weapon = NULL;
}

Character::Character(void){
	this->defaultInit("Nameless Protagonist");
}
Character::Character(const std::string& name){
	this->defaultInit(name);
}
Character::Character(const Character& other){
	*this = other;
}
Character::~Character(){
}

Character&	Character::operator =(const Character& other){
	this->name = other.name;
	this->actionPoints = other.actionPoints;
	this->actionPointsMax = other.actionPointsMax;
	this->weapon = other.weapon;
	return *this;
}

std::string	Character::getName() const { return this->name; }
int	Character::getAP() const    { return this->actionPoints;    }
int	Character::getAPMax() const { return this->actionPointsMax; }
const AWeapon*	Character::getWeapon() const { return this->weapon; }

std::ostream&	operator <<(std::ostream& dst, const Character& src){
	dst << src.getName() << " has " << src.getAP();
	if (!src.getWeapon())
		dst << " and is unarmed";
	else
		dst << " and wields a " << src.getWeapon()->getName();
	dst << std::endl;
	return dst;
}
