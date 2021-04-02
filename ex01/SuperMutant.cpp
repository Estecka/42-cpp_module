/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:05:42 by abaur             #+#    #+#             */
/*   Updated: 2021/04/02 14:36:31 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "SuperMutant.hpp"

SuperMutant::SuperMutant(void)
: Enemy(80, "Super Mutant") {
	this->deathCry = "Aaargh...";
}

SuperMutant::SuperMutant(const SuperMutant& other)
: Enemy(other) {
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
