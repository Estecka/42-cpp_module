/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiningBarge.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:38:47 by abaur             #+#    #+#             */
/*   Updated: 2021/04/05 17:32:14 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiningBarge.hpp"

#include <exception>

MiningBarge::MiningBarge(void){
	for (int i=0; i<LASERMAX; i++)
		this->equipment[i] = NULL;
	this->laserCount = 0;
	this->wallet = 0;
}
MiningBarge::MiningBarge(const MiningBarge& other){
	*this = other;
}
MiningBarge::~MiningBarge(){
	for (unsigned i=0; i<this->laserCount; i++)
		delete this->equipment[i];
}

MiningBarge&	MiningBarge::operator=(const MiningBarge& other){
	(void)other;
	throw std::invalid_argument("Mining barge copy not supported");
}

unsigned	MiningBarge::getLaserCount() const { return this->laserCount; }
int	MiningBarge::getMoney() const { return this->wallet; }

const IMiningLaser* MiningBarge::getLaser(unsigned index) const {
	if (index < 0 || laserCount <= index)
		return NULL;
	return this->equipment[index];
}

bool	MiningBarge::equip(IMiningLaser* item){
	if (item == NULL || this->laserCount >= LASERMAX)
		return false;
	
	this->equipment[this->laserCount] = item;
	this->laserCount++;
	return true;
}

IMiningLaser* MiningBarge::unequip(unsigned index){
	if (index < 0 || this->laserCount <= index)
		return NULL;
	
	IMiningLaser* item = this->equipment[index];
	for (unsigned i=index; i<laserCount-1; i++)
		this->equipment[i] = this->equipment[i+1];
	this->equipment[laserCount-1] = NULL;
	laserCount--;

	return item;
}

void	MiningBarge::addMoney(int amount) {
	this->wallet += amount;
}

int	MiningBarge::mine(IAsteroid* target) const {
	if (target == NULL)
		return 0;

	int	worth = 0;
	for (unsigned i=0; i<laserCount; i++){
		std::string result = this->equipment[i]->mine(target);
		// increase worth
	}
	return worth;
}
