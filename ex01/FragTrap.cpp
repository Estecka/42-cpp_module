/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 18:57:11 by abaur             #+#    #+#             */
/*   Updated: 2021/03/27 15:37:34 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include <iostream>
#include <stdlib.h>

FragTrap::FragTrap(void){
	std::cout << "A FR4G-TP came out of the factory with... well... factory settings." << std::endl;
	this->name = "Billy the default FR4G-TRAP";
	this->hitPoints = 100;
	this->hitPointsMax = 100;
	this->energyPoints = 100;
	this->energyPointsMax = 100;
	this->level = 1;
	this->atkMelee = 30;
	this->atkRanged = 20;
	this->def = 5;
}
FragTrap::FragTrap(const FragTrap& original){
	std::cout << original.name << " was ilegally cloned !" << std::endl;
	*this = original;
}
FragTrap::FragTrap(std::string name){
	std::cout << "A new, unique FR4G-TP came up: " << name << std::endl;
	this->name = name;
	this->hitPoints = 100;
	this->hitPointsMax = 100;
	this->energyPoints = 100;
	this->energyPointsMax = 100;
	this->level = 1;
	this->atkMelee = 30;
	this->atkRanged = 20;
	this->def = 5;
}
FragTrap::~FragTrap(){
	std::cout << this->name << " accidentally initiated their self-destruction "\
		<< "protocole. Now they look like a small smoking crater. Isn't that " \
		<< "an nice improvement ?" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& original){
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


void	FragTrap::meleeAttack(std::string targetName) {
	if (this->hitPoints <= 0) {
		std::cout << name << " tried their best to attack, but couldn't do it "\
			<< "because they're _dead_. " << targetName << " laughes at this "\
			<< "vain effort." << std::endl;
		return;
	}
	std::cout << name << " gave an unsolicited high-five to " << targetName \
		<< ", causing them to fall over and take -" << atkMelee << "HP."
		<< std::endl;
}

void	FragTrap::rangedAttack(std::string targetName) {
	if (this->hitPoints <= 0) {
			std::cout << targetName << " is too far away from robo-heaven for "\
				<< name << " to be able to attack." << std::endl;
		return; 
	}
	std::cout << name << " casually spoke to " << targetName << ". However " \
		<< name << " was holding the Megaphone from cpp00, thus dealing -" \
		<< atkRanged << "HP to their ears." << std::endl;
}

void	FragTrap::takeDamage(unsigned int dmgAmount) {
	if (this->hitPoints <= 0) {
		std::cout << name << "'s wreck is taking more damages. It's beating a "\
			<< "dead horse at this point." << std::endl;
	}
	else {
		if (dmgAmount < (unsigned)this->def)
			dmgAmount = 0;
		else
			dmgAmount -= this->def;

		if (dmgAmount == 0){
			std::cout << name << " came out of this without even a scrach."
				<< std::endl;
		}
		else {
			if (dmgAmount < (unsigned)this->hitPoints)
				this->hitPoints -= dmgAmount;
			else
				this->hitPoints = 0;
			std::cout << name << " forgot to free a pointer. The burden of "\
				<< "those leaked memories deals them -" << dmgAmount << "HP."\
				<< std::endl;
		}
	}
	std::cout << "(" << hitPoints << "/" << hitPointsMax << ")" << std::endl;
}

void	FragTrap::beRepaired(unsigned int healAmount){
	if (this->hitPoints >= hitPointsMax) {
		std::cout << name << " is in top shape and ready to fight !" << std::endl;
	}
	else {
		unsigned healMax = this->hitPointsMax - this->hitPoints;
		if (healAmount > healMax)
			healAmount = healMax;
		this->hitPoints += healAmount;
		std::cout << name << " ran Valgrind. They heal for +" << healAmount << "HP !" << std::endl;
	}
	std::cout << "(" << hitPoints << "/" << hitPointsMax << ")" << std::endl;
}

void	FragTrap::vaulthunter_dot_exe(std::string targetName){
	if (this->hitPoints <= 0){
		std::cout << name << "'s best effort to look awesome cannot overcome "\
			<< "death himself." << std::endl;
		return;
	}
	if (this->energyPoints < 25){
		std::cout << name << " attempts to do a sick backwheel flip, but "\
			<< "they don't have enough energy, and instead flop to the ground "\
			<< "like a wet sponge." << std::endl;
		return ;
	}
	energyPoints -= 25;
	switch (rand() % 5)
	{
		default: std::cout << name << " performs a magic trick in front of "\
			<< targetName << ". The sheer awesomness of this trick blows them "\
			<< "away, literally." << std::endl;
			break;
		case 1: std::cout << name << " gathers all their willpower, and "\
			<< "summons a meteor that comes crashing onto " << targetName \
			<< ". Or maybe it was just a coincidence." << std::endl;
			break;
		case 2: std::cout << name << " multiplexes into the router, and "
			<< "reverse-compiles the firewall using " << targetName << "'s "\
			<< "MAC ip adress. This does not achieve anything, but the "\
			<< "anti-cheat system ends up banning " << targetName << " instead "\
			<< "of " << name << std::endl;
			break;
		case 3: std::cout << name << " opens their top trap. A smaller FR4G-TP "\
			<< "comes out of it and... oh no, there's more coming, and they're "\
			<< "not stopping ! Run, " << targetName << " ! Run for your "\
			<< "life !" << std::endl;
			break;
		case 4: std::cout << name << " flamboyantly rips off their body shell, "\
			<< "exposing all their internal circuitery. This uncalled display "\
			<< "of robo-nudity scares " << targetName << " for life." << std::endl;
			break;
	}
}
