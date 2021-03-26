/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 18:57:11 by abaur             #+#    #+#             */
/*   Updated: 2021/03/26 19:16:29 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>


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
	this->name = original.name;
	this->hitPoints = original.hitPoints;
	this->hitPointsMax = original.hitPointsMax;
	this->energyPoints = original.energyPoints;
	this->energyPointsMax = original.energyPointsMax;
	this->level = original.level;
	this->atkMelee = original.atkMelee;
	this->atkRanged = original.atkRanged;
	this->def = original.def;
}
FragTrap::FragTrap(std::string name) : FragTrap(){
	std::cout << "Factory FR4G-TP, I hereby dub you " << name << std::endl;
	this->name = name;
}
FragTrap::~FragTrap(){
	std::cout << this->name << " accidentally initiated their self-destruction "\
		<< "protocole. Now they look like a small smoking crater. Isn't that " \
		<< "an nice improvement ?" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& original){
	*this = FragTrap(original);
}
