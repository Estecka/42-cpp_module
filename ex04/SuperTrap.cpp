/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:05:20 by abaur             #+#    #+#             */
/*   Updated: 2021/03/30 14:57:22 by abaur            ###   ########.fr       */
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

SuperTrap::SuperTrap(void){}
SuperTrap::SuperTrap(const SuperTrap& original){}
SuperTrap::SuperTrap(std::string name){}
SuperTrap::~SuperTrap(){}

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
