/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:08:58 by abaur             #+#    #+#             */
/*   Updated: 2021/03/18 19:56:56 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

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
	std::cout << this->name << " was destroyed." << std::endl;
}

bool	Pony::Sleep(){
	if (this->isAlive) {
		std::cout << this->name << " went to sleep." << std::endl; \
			;
		if (this->isAwake)
			std::cout << "Good dreams, " << this->name << "." << std::endl;
		else
			std::cout << "It's like a dream within a dream." << std::endl;
		this->isAwake = false;
		return true;
	}
	else {
		std::cout << this->name << " is already sleeping, very, VERY deeply." \
			<< std::endl;
		return false;
	}
}

bool	Pony::WakeUp(){
	if (!this->isAlive) {
		std::cout << "You attempt to wake " << this->name << " up, but they won\
't budge, whatever you do." << std::endl;
		return false;
	}
	else if (this->isAwake) {
		std::cout << "You shout at " << this->name << ", but they're already up\
. They look at you with a concerned look on their horsy face." << std::endl;
		return true;
	}
	else {
		std::cout << "Rise and shine, " << this->name << ". rise, and shine..."\
			<< std::endl;
		return true;
	}
}
