/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:19:21 by abaur             #+#    #+#             */
/*   Updated: 2021/03/28 16:10:06 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void	FragTrap::defaultInit(void){
	this->name = "FraggyChan the default FR4G-TP";
	this->hitPoints = 100;
	this->hitPointsMax = 100;
	this->energyPoints = 100;
	this->energyPointsMax = 100;
	this->level = 1;
	this->atkMelee = 30;
	this->atkRanged = 20;
	this->def = 5;
}

FragTrap::FragTrap(void) : ClapTrap(){
	msgDefaultConstructor();
	defaultInit();
}
FragTrap::FragTrap(const FragTrap& original) : ClapTrap(original){
	msgCopyConstructor(original);
	*this = original;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name){
	msgNamedConstructor(name);
}
FragTrap::~FragTrap(){
	msgDestructor();
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

#pragma clang diagnostic ignored "-Wunused-parameter"

void	FragTrap::vaulthunter_dot_exe(std::string targetName){
	if (this->hitPoints <= 0){
		msgNoHealth();
		return;
	}
	if (this->energyPoints < 25){
		msgNoEnergy();
		return;
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

void	FragTrap::msgDefaultConstructor(void) const {
	std::cout << name << "received a default FR4G-TP mod !"\
		<< std::endl;
}
void	FragTrap::msgCopyConstructor(const FragTrap& original) const {
	(void)original;
	std::cout << original.name << " also copied a FR4G-TP mod !"\
		<< std::endl;
}
void	FragTrap::msgNamedConstructor(std::string name) const {
	(void)name;
	std::cout << name << " received a named FR4G-TP mod !"\
		<< std::endl;
}
void	FragTrap::msgDestructor() const {
	std::cout << name << "'s FR4G-TP module self-destruction: enabled"\
		<< std::endl;
}

void	FragTrap::msgMelee(std::string targetName) const {
	std::cout << name << " gave an unsolicited high-five to " << targetName \
		<< ", causing them to fall over and take " << atkMelee << "dmg."\
		<< std::endl;
}
void	FragTrap::msgRanged(std::string targetName) const {
	std::cout << name << " casually spoke to " << targetName << ". However " \
		<< name << " was holding the Megaphone from cpp00, thus dealing "\
		<< atkRanged << "dmg to their ears."\
		<< std::endl;
}
void	FragTrap::msgDamage(unsigned amount) const {
	std::cout << name << " forgot to free a pointer. The burden of "\
		<< "those leaked memories deals them -" << amount << "HP."\
		<< std::endl;
}
void	FragTrap::msgNoDamage() const {
		std::cout << name << " came out of this without even a scrach !"\
			<< std::endl;
}
void	FragTrap::msgAlreadyDead() const {
	std::cout << name << "'s wreck is taking more damages. It's beating a "\
		<< "dead horse at this point."\
		<< std::endl;
}
void	FragTrap::msgHeal(unsigned amount) const {
	std::cout << name << " ran Valgrind. They heal for +" << amount << "HP !"\
	<< std::endl;
}
void	FragTrap::msgFullHealth() const {
	std::cout << name << " is in top shape and ready to fight !"\
	<< std::endl;
}
void	FragTrap::msgNoEnergy() const {
	std::cout << name << " attempts to do a sick backwheel flip, but "\
		<< "they don't have enough energy, and instead flop to the ground "\
		<< "like a wet sponge."\
		<< std::endl;
}
void	FragTrap::msgNoHealth() const {
	std::cout << name << "'s best efforts to look awesome can never overcome "\
		<< "death himself."\
		<< std::endl;
}