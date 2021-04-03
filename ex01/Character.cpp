/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:11:16 by abaur             #+#    #+#             */
/*   Updated: 2021/04/03 14:51:34 by abaur            ###   ########.fr       */
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
AWeapon*	Character::getWeapon() const { return this->weapon; }

void	Character::recoverAP(){
	this->actionPoints += 10;
	if (this->actionPoints > this->actionPointsMax)
		this->actionPoints = this->actionPointsMax;
}
void	Character::equip(AWeapon* weapon){
	this->weapon = weapon;
}
bool	Character::attack(Enemy* enemy){
	if (enemy && weapon && this->actionPoints >= weapon->getAPCost()) {
		std::cout << this->name << " attacks " << enemy->getType() \
			<< " with a " << weapon->getName() << std::endl;
		this->actionPoints -= weapon->getAPCost();
		int dmg = weapon->getDamage();
		weapon->attack();
		enemy->takeDamage(dmg);
		if (enemy->getHP() <= 0){
			delete enemy;
			return true;
		}
	}
	return false;
}

std::ostream&	operator <<(std::ostream& dst, const Character& src){
	dst << src.getName() << " has " << src.getAP() << " AP and ";
	if (!src.getWeapon())
		dst << "is unarmed";
	else
		dst << "wields a " << src.getWeapon()->getName();
	dst << std::endl;
	return dst;
}
