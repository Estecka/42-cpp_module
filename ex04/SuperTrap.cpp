/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:05:20 by abaur             #+#    #+#             */
/*   Updated: 2021/03/30 15:50:43 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

#pragma clang diagnostic ignored "-Wunused-parameter"

void	SuperTrap::defaultInit(void){
	this->name = "SoupError, the default 2UP3R-TP";
	this->level = 1;

	this->hitPoints    = this->FragTrap::hitPoints;
	this->hitPointsMax = this->FragTrap::hitPointsMax;
	this->atkRanged    = this->FragTrap::atkRanged;
	this->def          = this->FragTrap::def;

	this->energyPoints    = this->NinjaTrap::energyPoints;
	this->energyPointsMax = this->NinjaTrap::energyPointsMax;
	this->atkMelee        = this->NinjaTrap::atkMelee;
}

SuperTrap::SuperTrap(void) 
: ClapTrap(), NinjaTrap(), FragTrap()
{
	this->defaultInit();
	this->msgDefaultConstructor();
}
SuperTrap::SuperTrap(const SuperTrap& original) 
: ClapTrap(original), NinjaTrap(original), FragTrap(original)
{
	*this = original;
	this->msgCopyConstructor(original);
}
SuperTrap::SuperTrap(std::string name)
: ClapTrap(name), NinjaTrap(name), FragTrap(name)
{
	this->defaultInit();
	this->name = name;
	this->msgNamedConstructor(name);
}
SuperTrap::~SuperTrap(){
	this->msgDestructor();
}

SuperTrap& SuperTrap::operator =(const SuperTrap& original){
	this->name = original.name;
	this->hitPoints = original.hitPoints;
	this->hitPointsMax = original.hitPointsMax;
	this->energyPoints = original.energyPoints;
	this->energyPointsMax = original.energyPointsMax;
	this->atkMelee = original.atkMelee;
	this->atkRanged = original.atkRanged;
	this->def = original.def;
	return *this;
}

void	SuperTrap::msgMelee(std::string targetName)  const { this->NinjaTrap::msgMelee(targetName); }
void	SuperTrap::msgRanged(std::string targetName) const { this->FragTrap::msgRanged(targetName); }

void	SuperTrap::msgDamage(unsigned amount) const { this->ClapTrap::msgDamage(amount); }
void	SuperTrap::msgHeal(unsigned amount)   const { this->ClapTrap::msgHeal(amount);   }
void	SuperTrap::msgNoDamage()    const { this->ClapTrap::msgNoDamage();    }
void	SuperTrap::msgAlreadyDead() const { this->ClapTrap::msgAlreadyDead(); }
void	SuperTrap::msgFullHealth()  const { this->ClapTrap::msgFullHealth();  }
void	SuperTrap::msgNoEnergy()    const { this->ClapTrap::msgNoEnergy();    }
void	SuperTrap::msgNoHealth()    const { this->ClapTrap::msgNoHealth();    }

void	SuperTrap::msgDefaultConstructor() const{
	std::cout << "What's happening? " << name << " evolved into a default "\
		<< "2UP3R-TP !"\
		<< std::endl;
}
void	SuperTrap::msgCopyConstructor(const SuperTrap& original) const{
	std::cout << "What's happening? " << name << " evolved into a copied "\
		<< "2UP3R-TP !"\
		<< std::endl;
}
void	SuperTrap::msgNamedConstructor(std::string name) const{
	std::cout << "What's happening? " << name << " evolved into a named "\
		<< "2UP3R-TP !"\
		<< std::endl;
}
void	SuperTrap::msgDestructor() const {
	std::cout << name << "'s diamond structure is tearing at the seams. "\
		<< "Looks like diamond's not unbreakable after all."\
		<< std::endl;
}
