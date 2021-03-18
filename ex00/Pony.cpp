/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:08:58 by abaur             #+#    #+#             */
/*   Updated: 2021/03/18 22:09:32 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

#include <stdlib.h>

Pony::Pony(void){
	this->name = "Johny the Default Pony";
	this->robeColor = "blank";

	this->isAlive = true;
	this->isAwake = true;

	this->legsBroken = 0;
}

Pony::Pony(std::string name, std::string robeColor) {
	this->name = name;
	this->robeColor = robeColor;

	this->isAlive = true;
	this->isAwake = true;

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
		std::cout << name << " is sleeping, very, very deeply." << std::endl;
		return false;
	}
}

bool	Pony::WakeUp(){
	if (!this->isAlive) {
		std::cout << "You attempt to wake " << name << " up, "\
			<< "but whatever you do, they won't budge." << std::endl;
		return false;
	}
	else if (this->isAwake) {
		std::cout << "You shout at " << name << ", but they're already awake. "\
			<< "They look at you with a concerned look on their horsy face." \
			<< std::endl;
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
		std::cout << name << " broke all their legs. Unable to keep going, "\
			<< "they eventually succumbe to their wounds." << std::endl;
		this->isAlive = false;
		this->isAwake = false;
	}
}

bool	Pony::Jump() {
	if (!this->isAlive) {
		return false;
	} else if (this->legsBroken >= 4) {
		std::cout << name << " is unable to jump." << std::endl;
		return false;
	} else if (!this->isAwake) {
		std::cout << name << " attempts to jump in their sleep. Doing so, they"\
			<< " break a leg." << std::endl;
		this->BreakALeg();
		return true;
	} else {
		if (this->legsBroken)
			std::cout << name << " clumsily attempts to jump." << std::endl;
		else
			std::cout << name << " performs a majestuous jump." << std::endl;
		if (!(rand() % 4)) {
			std::cout << "Unfortunately, they break a leg as they land." \
				<< std::endl;
			this->BreakALeg();
		}
		return true;
	}
}

bool	Pony::Walk() {
	if (!this->isAlive)
		return false;
	else {
		if (!this->isAwake){
			std::cout << name << " starts sleepwalking." << std::endl;
			if (!(rand() % 3)) {
				std::cout << "Unable to see their surrounding, they twist a le"\
					<< "g on a pebble." << std::endl;
				this->BreakALeg();
			}
		}
		else if (this->legsBroken) {
			std::cout << name << " limps with difficulty toward you." \
				<< std::endl;
			if (!(rand() % 4)) {
				std::cout << "So much difficulty in fact, that they twist anot"\
					<< "her leg." << std::endl;
				this->BreakALeg();
			}
		}
		else
			std::cout << name << " walks happyly toward you." << std::endl;
		return true;
	}
}

bool	Pony::Run() {
	if (!this->isAlive)
		return false;
	else {
		if (!this->isAwake) {
			std::cout << name << " starts sleepwalking, but faster than usual."\
				<< std::endl;
			if (!(rand() % 2)){
				std::cout << "So fast, and so blindly, that they run into a wa"\
					<< "ll, and break one of their leg." << std::endl;
				this->BreakALeg();
			}
		} 
		else {
			if (!this->legsBroken)
				std::cout << name << " runs valiantly across the field." \
					<< std::endl;
			else
				std::cout << name << " walks as fast as their broken legs allo"\
					<< "w them to." << std::endl;
			if (!(rand() % 2)){
				std::cout << "The effort required for this prowess proves too "\
					<< "much for " << name << ", and so, they inadvertantly tw"\
					<< "ist a leg." << std::endl;
				this->BreakALeg();
			}
		}
		return true;
	}
}
