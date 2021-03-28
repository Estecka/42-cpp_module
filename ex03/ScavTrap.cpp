/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 17:20:45 by abaur             #+#    #+#             */
/*   Updated: 2021/03/28 17:46:26 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include <stdlib.h>

void	ScavTrap::defaultInit(void){
	this->hitPoints = 100;
	this->hitPointsMax = 100;
	this->energyPoints = 50;
	this->energyPointsMax = 50;
	this->level = 1;
	this->atkMelee = 20;
	this->atkRanged = 15;
	this->def = 3;
}

ScavTrap::ScavTrap(void) : ClapTrap(){
	msgDefaultConstructor();
	defaultInit();
	this->name = "Scarcity the default SC4V-TP";
}
ScavTrap::ScavTrap(const ScavTrap& original) : ClapTrap(original){
	msgCopyConstructor(original);
	*this = original;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	msgNamedConstructor(name);
	defaultInit();
	this->name = name;
}
ScavTrap::~ScavTrap(){
	msgDestructor();
}

ScavTrap& ScavTrap::operator=(const ScavTrap& original){
	*(ClapTrap*)this = *(const ClapTrap*)&original;
	return *this;
}

void	ScavTrap::challengeNewcomer(){
	if (this->hitPoints <= 0){
		msgNoHealth();
		return;
	}
	if (this->energyPoints < 25){
		msgNoEnergy();
		return ;
	}
	energyPoints -= 25;
	std::cout << "<" << name << ">: Oh, so you wish to pass through ? ";
	switch (rand() % 5)
	{
		default:
			std::cout << "Try and take care of that FR4G-TP first.";
			break;
		case 1:
			std::cout << "Go fetch me some coffee, then I'll consider it.";
			break;
		case 2:
			std::cout << "Over my dead body !";
			break;
		case 3:
			std::cout << "For that you'll need to carry the ring to Mordor "\
			<< "Sorry, I don't make the rules.";
			break;
		case 4:
			std::cout << "Dance for me, first. Dance I say !";
			break;
	}
	std::cout << std::endl;
}

void	ScavTrap::msgDefaultConstructor(void) const {
	std::cout << "The default CL4P-TP received a default SC4V-TP mod !"\
		<< std::endl;
}
void	ScavTrap::msgCopyConstructor(const ScavTrap& original) const {
	(void)original;
	std::cout << original.name << " also copied a SC4V-TP mod !"\
		<< std::endl;
}
void	ScavTrap::msgNamedConstructor(std::string name) const {
	(void)name;
	std::cout << name << " now has a SC4V-TP mod to their name !"\
		<< std::endl;
}
void	ScavTrap::msgDestructor() const {
	std::cout << name << "'s SC4V-TP module self-destruction: enabled"\
		<< std::endl;
}

void	ScavTrap::msgMelee(std::string targetName) const {
	std::cout << name << " rammed " << targetName << ", causing them to fall "\
		<< "over and take " << atkMelee << "dmg."\
		<< std::endl;
}
void	ScavTrap::msgRanged(std::string targetName) const {
	std::cout << name << " threw a sharp rock at " << targetName << ", "\
		<< "dealing " << atkRanged << "dmg."\
		<< std::endl;
}
void	ScavTrap::msgDamage(unsigned amount) const {
	std::cout << name << " overflowed their stack. "\
		<< "They take -" << amount << "HP."\
		<< std::endl;
}
void	ScavTrap::msgNoDamage() const {
	std::cout << name << " didn't even flinch !"\
		<< std::endl;
}
void	ScavTrap::msgAlreadyDead() const {
	std::cout << "Stop ! " << name << " is already dead !"\
		<< std::endl;
}
void	ScavTrap::msgHeal(unsigned amount) const {
	std::cout << name << " bought some extra RAM for their stack, "\
		<< "they heal for +" << amount << "HP !"\
		<< std::endl;
}
void	ScavTrap::msgFullHealth() const {
	std::cout << name << " feels like they could take over the world !"\
		<< std::endl;
}
void	ScavTrap::msgNoEnergy() const {
	std::cout << name << " lags out due to a lack of energy, and couldn't "\
		<< "think of any sick burn."\
		<< std::endl;
}
void	ScavTrap::msgNoHealth() const {
	std::cout << name << " is in no shape to perform this action."\
		<< std::endl;
}
