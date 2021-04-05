/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:05:42 by abaur             #+#    #+#             */
/*   Updated: 2021/04/05 14:11:42 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

SuperMutant::SuperMutant(void)
: Enemy(170, "Super Mutant") {
	this->deathCry = "Aaargh...";
	std::cout << "Gaah. Me want smash heads!" << std::endl;
}

SuperMutant::SuperMutant(const SuperMutant& other)
: Enemy(other) {
	std::cout << "Gaah. Me want smash heads!" << std::endl;
}

SuperMutant::~SuperMutant(){
}

SuperMutant& SuperMutant::operator =(const SuperMutant& other){
	this->Enemy::operator=(other);
	return *this;
}

void	SuperMutant::takeDamage(int dmgAmount){
	if (dmgAmount > 3)
		dmgAmount -= 3;
	else
		dmgAmount = 0;
	this->Enemy::takeDamage(dmgAmount);
}
