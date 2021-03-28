/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 18:20:09 by abaur             #+#    #+#             */
/*   Updated: 2021/03/28 19:08:49 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

void	NinjaTrap::defaultInit(void){
	this->hitPoints = 60;
	this->hitPointsMax = 60;
	this->energyPoints = 120;
	this->energyPointsMax = 120;
	this->level = 1;
	this->atkMelee = 60;
	this->atkRanged = 5;
	this->def = 0;
}

NinjaTrap::NinjaTrap(void) : ClapTrap(){
	msgDefaultConstructor();
	defaultInit();
	this->name = "Jacky the default N1NJ4-TP";
}
NinjaTrap::NinjaTrap(const NinjaTrap& original) : ClapTrap(original){
	msgCopyConstructor(original);
	*this = original;
}
NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name){
	msgNamedConstructor(name);
	defaultInit();
	this->name = name;
}
NinjaTrap::~NinjaTrap(){
	msgDestructor();
}

NinjaTrap& NinjaTrap::operator=(const NinjaTrap& original){
	*(ClapTrap*)this = *(const ClapTrap*)&original;
	return *this;
}

void	NinjaTrap::ninjaShoebox(const ClapTrap& target){
	std::cout << this->name << " clapped the trap of " << target.getName() << " !"\
		<< std::endl;
}
void	NinjaTrap::ninjaShoebox(const FragTrap& target){
	std::cout << this->name << " threw a fragmentation grenade at " << target.getName() << " !"\
		<< std::endl;
}
void	NinjaTrap::ninjaShoebox(const ScavTrap& target){
	std::cout << this->name << " looted the body of " << target.getName() << " !"\
		<< std::endl;
}
void	NinjaTrap::ninjaShoebox(const NinjaTrap& target){
	if (this == &target)
		std::cout << this->name << " is congratulating himself."\
			<< std::endl;
	else
		std::cout << "There can only be one N1NJ4-TP ! "\
			<< this->name << " and " << target.getName() << " are fighting to "\
			<< "the death, in an impressive display of acrobatic figures. "\
			<< "None of them have managed to come out on top so far."\
			<< std::endl;
}


void	NinjaTrap::msgDefaultConstructor(void) const {
	std::cout << "The default CL4P-TP received a default N1NJ4-TP mod !"\
		<< std::endl;
}
void	NinjaTrap::msgCopyConstructor(const NinjaTrap& original) const {
	(void)original;
	std::cout << original.name << " also copied a N1NJ4-TP mod !"\
		<< std::endl;
}
void	NinjaTrap::msgNamedConstructor(std::string name) const {
	(void)name;
	std::cout << name << " now has a N1NJ4-TP mod to their name !"\
		<< std::endl;
}
void	NinjaTrap::msgDestructor() const {
	std::cout << name << "'s N1NJ4-TP module self-destruction: enabled"\
		<< std::endl;
}

void	NinjaTrap::msgMelee(std::string targetName) const {
	std::cout << name << " struck " << targetName << " from the shadows, "\
		<< "dealing " << atkMelee << "dmg."\
		<< std::endl;
}
void	NinjaTrap::msgRanged(std::string targetName) const {
	std::cout << name << " flinged a needle toward " << targetName << ", "\
		<< "dealing " << atkRanged << "dmg."\
		<< std::endl;
}
void	NinjaTrap::msgDamage(unsigned amount) const {
	std::cout << name << " didn't see that one coming. "\
		<< "They take -" << amount << "HP."\
		<< std::endl;
}
void	NinjaTrap::msgNoDamage() const {
		std::cout << name << " dodged everything ! Somehow."\
			<< std::endl;
}
void	NinjaTrap::msgAlreadyDead() const {
	std::cout << name << "'s grave is being desacralised."\
		<< std::endl;
}
void	NinjaTrap::msgHeal(unsigned amount) const {
	std::cout << name << " refocused their robo-shakra. "\
		<< "They heal for +" << amount << "HP !"\
		<< std::endl;
}
void	NinjaTrap::msgFullHealth() const {
	std::cout << name << " is now the mightiest trap in the known universe !"\
		<< std::endl;
}
void	NinjaTrap::msgNoEnergy() const {
	std::cout << name << "'s ki is failing. This effort is vain."\
		<< std::endl;
}
void	NinjaTrap::msgNoHealth() const {
	std::cout << name << "'s determination failed them. "\
		<< "They can't take this action."\
		<< std::endl;
}
