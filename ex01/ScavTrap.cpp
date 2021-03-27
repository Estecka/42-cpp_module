/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 18:57:11 by abaur             #+#    #+#             */
/*   Updated: 2021/03/27 16:04:56 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include <iostream>
#include <stdlib.h>

ScavTrap::ScavTrap(void){
	std::cout << "A generic SC4V-TP was built from scraps." << std::endl;
	this->name = "Billy the default SC4V-TP";
	this->hitPoints = 100;
	this->hitPointsMax = 100;
	this->energyPoints = 50;
	this->energyPointsMax = 50;
	this->level = 1;
	this->atkMelee = 20;
	this->atkRanged = 15;
	this->def = 3;
}
ScavTrap::ScavTrap(const ScavTrap& original){
	std::cout << original.name << " made a statue of themselves, and the "\
		<< "statue came to life. There are two of them now." << std::endl;
	*this = original;
}
ScavTrap::ScavTrap(std::string name){
	std::cout << "A remarkable SC4V-TP managed to build themselves : " << name << std::endl;
	this->name = name;
	this->hitPoints = 100;
	this->hitPointsMax = 100;
	this->energyPoints = 50;
	this->energyPointsMax = 50;
	this->level = 1;
	this->atkMelee = 20;
	this->atkRanged = 15;
	this->def = 3;
}
ScavTrap::~ScavTrap(){
	std::cout << this->name << " accidentally initiated their self-destruction "\
		<< "protocole. Now they look like a pile of unassorted screws." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& original){
	this->name = original.name;
	this->hitPoints = original.hitPoints;
	this->hitPointsMax = original.hitPointsMax;
	this->energyPoints = original.energyPoints;
	this->energyPointsMax = original.energyPointsMax;
	this->level = original.level;
	this->atkMelee = original.atkMelee;
	this->atkRanged = original.atkRanged;
	this->def = original.def;
	return *this;
}


void	ScavTrap::meleeAttack(std::string targetName) {
	if (this->hitPoints <= 0) {
		std::cout << name << " is in no shape for melee attacks." << std::endl;
		return;
	}
	std::cout << name << " rammed " << targetName << ", causing them to fall "\
		<< "over and take -" << atkMelee << "HP." << std::endl;
}

void	ScavTrap::rangedAttack(std::string targetName) {
	if (this->hitPoints <= 0) {
			std::cout << targetName << " is too far away from robo-hell for "\
				<< name << " to be able to attack." << std::endl;
		return; 
	}
	std::cout << name << " threw a sharp rock at " << targetName << " dealing -"\
		<< atkRanged << "HP." << std::endl;
}

void	ScavTrap::takeDamage(unsigned int dmgAmount) {
	if (this->hitPoints <= 0) {
		std::cout << "Stop! " << name << " is already dead !" << std::endl;
	}
	else {
		if (dmgAmount > (unsigned)this->hitPoints)
			dmgAmount = (unsigned)this->hitPoints;
		this->hitPoints -= dmgAmount;
		std::cout << name << " overflowed their stack, they take -" \
			<< dmgAmount << "HP." << std::endl;
	}
	std::cout << "(" << hitPoints << "/" << hitPointsMax << ")" << std::endl;
}

void	ScavTrap::beRepaired(unsigned int healAmount){
	if (this->hitPoints >= hitPointsMax) {
		std::cout << name << " feels like they could take over the world !" << std::endl;
	}
	else {
		unsigned healMax = this->hitPointsMax - this->hitPoints;
		if (healAmount > healMax)
			healAmount = healMax;
		this->hitPoints += healAmount;
		std::cout << name << " bought some extra RAM, they heal for +" \
			<< healAmount << "HP !" << std::endl;
	}
	std::cout << "(" << hitPoints << "/" << hitPointsMax << ")" << std::endl;
}

void	ScavTrap::challengeNewcomer(){
	if (this->hitPoints <= 0){
		std::cout << name << "'s sick burn cannot be heard, since they're dead."\
			 << std::endl;
		return;
	}
	if (this->energyPoints < 25){
		std::cout << name << " lags out, and is unable to think of any cool "\
			<< "comeback." << std::endl;
		return ;
	}
	energyPoints -= 25;
	std::cout << "<" << name << ">: Oh, so you wish to pass through ? ";
	switch (rand() % 5)
	{
		default: std::cout << "Try and take care of that FR4G-TP first." 
			break;
		case 1: std::cout << "Over my dead body !";
			break;
		case 2: std::cout << "Go fetch me some coffee, then I'll consider it.";
			break;
		case 3: std::cout << "For that you'll need to carry the ring to Mordor "\
			<< "Sorry, I don't make the rules."
			break;
		case 4: std::cout << "Dance for me, first. Dance I say !";
			break;
	}
	std::cout << std::endl;
}
