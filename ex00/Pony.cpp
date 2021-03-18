/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:08:58 by abaur             #+#    #+#             */
/*   Updated: 2021/03/18 21:03:16 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

#include <stdlib.h>

Pony::Pony(void){
	this->name = "Johny the Default Pony";
	this->robeColor = "blank";

	this->isAlive = true;
	this->isAwake = true;

	this->distanceWalked = 0;
	this->legsBroken = 0;
}

Pony::Pony(std::string name, std::string robeColor) {
	this->name = name;
	this->robeColor = robeColor;

	this->isAlive = true;
	this->isAwake = true;

	this->distanceWalked = 0;
	this->legsBroken = 0;
}

Pony::~Pony(){
	std::cout << name << " was destroyed." << std::endl;
}

bool	Pony::Sleep(){
	if (this->isAlive) {
		std::cout << name << " went to sleep." << std::endl; \
			;
		if (this->isAwake)
			std::cout << "Good dreams, " << name << "." << std::endl;
		else
			std::cout << "It's like a dream within a dream." << std::endl;
		this->isAwake = false;
		return true;
	}
	else {
		std::cout << name << " is already sleeping, very, VERY deeply." \
			<< std::endl;
		return false;
	}
}

bool	Pony::WakeUp(){
	if (!this->isAlive) {
		std::cout << "You attempt to wake " << name << " up, but they won\
't budge, whatever you do." << std::endl;
		return false;
	}
	else if (this->isAwake) {
		std::cout << "You shout at " << name << ", but they're already up\
. They look at you with a concerned look on their horsy face." << std::endl;
		return true;
	}
	else {
		std::cout << "Rise and shine, " << name << ". rise, and shine..."\
			<< std::endl;
		this->isAwake = true;
		return true;
	}
}

void	Pony::BreakALeg(){
	this->legsBroken++;
	if (this->legsBroken >= 4){
		std::cout << name << " broke all their legs. Unable to keep going, they\
 eventually succumbed to their wounds." << std::endl;
	}
}

bool	Pony::Jump() {
	if (!this->isAlive) {
		return false;
	} else if (this->legsBroken >= 4) {
		std::cout << name << " is unable to jump." << std::endl;
		return false;
	} else if (!this->isAwake) {
		std::cout << name << " attempts to jump in their sleep. Doing so, they \
break a leg." << std::endl;
		this->BreakALeg();
		return true;
	} else {
		if (this->legsBroken)
			std::cout << name << " Clumsily attempts to jump.";
		else
			std::cout << name << " performs a majestuous jump.";
		if (!(rand() % 4)) {
			std::cout << " Unfortunately, they break a leg when landing.";
			this->BreakALeg();
		}
		std::cout << std::endl;
		return true;
	}
}
