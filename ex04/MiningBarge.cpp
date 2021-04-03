/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiningBarge.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:38:47 by abaur             #+#    #+#             */
/*   Updated: 2021/04/04 00:05:30 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiningBarge.hpp"

#include <exception>

MiningBarge::MiningBarge(void){
	for (int i=0; i<LASERMAX; i++)
		this->equipment[i] = NULL;
	this->laserCount = 0;
}
MiningBarge::MiningBarge(const MiningBarge& other){
	*this = other;
}
MiningBarge::~MiningBarge(){
	for (int i=0; i<this->laserCount; i++)
		delete this->equipment[i];
}

MiningBarge&	MiningBarge::operator=(const MiningBarge& other){
	throw std::invalid_argument("Mining barge copy not supported");
}

bool	MiningBarge::equip(IMiningLaser* item){
	if (item == NULL)
		throw std::invalid_argument("Null equipment");
	if (this->laserCount >= LASERMAX)
		return false;
	
	this->equipment[this->laserCount] = item;
	this->laserCount++;
}

IMiningLaser* MiningBarge::unequip(unsigned index){
	if (index < 0 || LASERMAX <= index)
		throw std::out_of_range("Invalid equipement slot");
	
	IMiningLaser* item = this->equipment[index];
	this->equipment[index] = NULL;
	return item;
}

int	MiningBarge::mine(IAsteroid* target) const {
	if (target == NULL)
		throw std::invalid_argument("Null target");

	int	worth = 0;
	for (int i=0; i<laserCount; i++){
		std::string result = this->equipment[i]->mine(target);
		// increase worth
	}
	return worth;
}
