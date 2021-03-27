/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 19:34:50 by abaur             #+#    #+#             */
/*   Updated: 2021/03/27 20:01:26 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	ClapTrap::defaultInit(void){
	this->name = "ClapityClap the default CL4P-TP";
	this->hitPoints = 1;
	this->hitPointsMax = 1;
	this->energyPoints = 1;
	this->energyPointsMax = 1;
	this->level = 1;
	this->atkMelee = 0;
	this->atkRanged = 0;
	this->def = 0;
}

ClapTrap::ClapTrap(void){
	msgDefaultConstructor();
	this->defaultInit();
}
ClapTrap::ClapTrap(const ClapTrap& original){
	msgCopyConstructor(original);
	*this = original;
}
ClapTrap::ClapTrap(std::string name){
	msgNamedConstructor(name);
	this->defaultInit();
	this->name = name;
}
ClapTrap::~ClapTrap(){
	msgDestructor();
}

ClapTrap& ClapTrap::operator=(const ClapTrap& original){
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


void	ClapTrap::meleeAttack(std::string targetName) {
	if (this->hitPoints <= 0)
		msgNoHealth();
	else
		msgMelee(targetName);
}

void	ClapTrap::rangedAttack(std::string targetName) {
	if (this->hitPoints <= 0)
		msgNoHealth();
	else
		msgRanged(targetName);
}

void	ClapTrap::takeDamage(unsigned int dmgAmount) {
	if (this->hitPoints <= 0)
		msgAlreadyDead();
	else {
		if (dmgAmount < (unsigned)this->def)
			dmgAmount = 0;
		else
			dmgAmount -= this->def;

		if (dmgAmount == 0)
			msgNoDamage();
		else {
			if (dmgAmount < (unsigned)this->hitPoints)
				this->hitPoints -= dmgAmount;
			else
				this->hitPoints = 0;
			msgDamage(dmgAmount);
		}
	}
	std::cout << "(" << hitPoints << "/" << hitPointsMax << ")" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int healAmount){
	if (this->hitPoints >= hitPointsMax)
		msgFullHealth();
	else {
		unsigned healMax = this->hitPointsMax - this->hitPoints;
		if (healAmount > healMax)
			healAmount = healMax;
		this->hitPoints += healAmount;
		msgHeal(healAmount);
	}
	std::cout << "(" << hitPoints << "/" << hitPointsMax << ")" << std::endl;
}


std::string	ClapTrap::msgDefaultConstructor(void) const{
	return "";
}
std::string	ClapTrap::msgCopyConstructor(const ClapTrap& original) const{
	return "";
}
std::string	ClapTrap::msgNamedConstructor(std::string name) const{
	return "";
}
std::string	ClapTrap::msgDestructor() const{
	return "";
}

std::string	ClapTrap::msgMelee(std::string targetName) const{
	return "";
}
std::string	ClapTrap::msgRanged(std::string targetName) const{
	return "";
}
std::string	ClapTrap::msgDamage(unsigned amount) const{
	return "";
}
std::string	ClapTrap::msgNoDamage() const{
	return "";
}
std::string	ClapTrap::msgAlreadyDead() const{
	return "";
}
std::string	ClapTrap::msgHeal(unsigned amount) const{
	return "";
}
std::string	ClapTrap::msgFullHealth() const{
	return "";
}
std::string	ClapTrap::msgNoEnergy() const{
	return "";
}
std::string	ClapTrap::msgNoHealth() const{
	return "";
}
