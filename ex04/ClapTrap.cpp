/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 19:34:50 by abaur             #+#    #+#             */
/*   Updated: 2021/03/28 18:47:51 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	ClapTrap::defaultInit(void){
	this->hitPoints = 10;
	this->hitPointsMax = 10;
	this->energyPoints = 25;
	this->energyPointsMax = 25;
	this->level = 1;
	this->atkMelee = 1;
	this->atkRanged = 1;
	this->def = 1;
}

ClapTrap::ClapTrap(void){
	msgDefaultConstructor();
	this->defaultInit();
	this->name = "ClapityClap the default CL4P-TP";
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

std::string	ClapTrap::getName() const { return this->name; }

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


void	ClapTrap::msgDefaultConstructor(void) const{
	std::cout << "A default CL4P-TP was built."\
		<< std::endl;
}
void	ClapTrap::msgCopyConstructor(const ClapTrap& original) const{
	std::cout << "A CL4P-TP was built by copying " << original.name << "."\
		<< std::endl;
}
void	ClapTrap::msgNamedConstructor(std::string name) const{
	std::cout << "A CL4P-TP was built, and hereby dubbed " << name << "."\
		<< std::endl;
}
void	ClapTrap::msgDestructor() const{
	std::cout << name << " accidentally triggered their self-destruct protocol. "\
		<< "Now they look like a small smoking crater. "\
		<< "Isn't that a nice improvement ?"\
		<< std::endl;
}

void	ClapTrap::msgMelee(std::string targetName) const{
	std::cout << name << " hit " << targetName << " with a shovel, "\
		<< "dealing " << atkMelee << "dmg."\
		<< std::endl;
}
void	ClapTrap::msgRanged(std::string targetName) const{
	std::cout << name << " threw a small pebble at " << targetName \
		<< ", dealing " << atkRanged << "dmg."\
		<< std::endl;
}
void	ClapTrap::msgDamage(unsigned amount) const{
	std::cout << name << "'s feeling were hurt for -" << amount << "HP."\
		<< std::endl;
}
void	ClapTrap::msgNoDamage() const{
	std::cout << name << " didn't even feel a thing !"\
		<< std::endl;
}
void	ClapTrap::msgAlreadyDead() const{
	std::cout << "You don't know it yet, but " << name \
		<< " is already dead."\
		<< std::endl;
}
void	ClapTrap::msgHeal(unsigned amount) const{
	std::cout << name << "'s feeling better. They gain +" << amount << "HP."\
		<< std::endl;
}
void	ClapTrap::msgFullHealth() const{
	std::cout << name << " is ready and kicking !" << std::endl;
}
void	ClapTrap::msgNoEnergy() const{
	std::cout << "If you see that message, something went wrong with " << name \
		<< std::endl;
}
void	ClapTrap::msgNoHealth() const{
	std::cout << name << " is kind of sick and can't do that right now. "\
		<< "Jk, they're completely dead."\
		<< std::endl;
}
