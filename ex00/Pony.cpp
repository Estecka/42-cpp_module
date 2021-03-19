/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:08:58 by abaur             #+#    #+#             */
/*   Updated: 2021/03/19 01:25:39 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

#include <stdlib.h>

Pony::Pony(std::string name, std::string robeColour) {
	this->name = name;
	this->robeColour = robeColour;

	this->isAlive = true;
	this->isAwake = true;

	this->legsBroken = 0;

	std::cout << "You welcome a new pony into the ranch. Their name is " \
		<< name << ", and their robe is coloured " << robeColour << "." << std::endl;
}

Pony::~Pony(){
	std::cout << "Your memories of "<< name << " are slowly fading away. " \
		<< "Their " << robeColour << " robe is now no more but a far-off ideal."\
		<< std::endl;
}

bool	Pony::Sleep(){
	if (this->isAlive) {
		std::cout << name << " went to sleep. ";
		if (this->isAwake)
			std::cout << "Good dreams, " << name << "." << std::endl;
		else
			std::cout << "Again. It's like a dream within a dream." << std::endl;
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
			<< "they eventually succumb to their wounds." << std::endl;
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

void	Pony::Shine(){
	if (!this->isAlive)
		std::cout << name << " shines in death like they shined in life. "\
			<< "Although with much less vitality." << std::endl;
	else if (!this->isAwake)
		std::cout << name << " dreams of Fame and Glory. As for what exactly m"\
			<< "akes up the details of this dream, our eyes are unable to perc"\
			<< "eive it." << std::endl;
	else
		std::cout << name << " raises their head, and proudly shows off their "\
			<< "splendid " << this->robeColour << " robe. Their magnificent coa"\
			<< "t shines magnificently, with much magnificence. A sight to beh"\
			<< "old." << std::endl;
}

void	Pony::Transcend(){
	if (!this->isAlive) {
		std::cout << "From the lowest depths of misfortune, " << name \
			<< " ascends to a new plane of existence. Their mind's eye opens. "\
			<< "They can see it clearly now, the path to eternal life. " \
			<< name << "'s once deceased body rises again; they shine brighter "\
			<< "than ever before, and, through a demonstration of sheer willpow"\
			<< "er, rejuvenate themselves." << std::endl;
		this->isAlive = true;
		this->isAwake = true;
		this->legsBroken = 0;
	}
	else if (!this->isAwake)
		std::cout << name << " enters a state of dream so deep, that it might "\
			<< "better be described as a transe. They almost manage to pierce "\
			<< "the secrets of life, but a nightmare steals it away before " \
			<< name << " is able to touch them." << std::endl;
	else
		std::cout << name << " reflects upon their life. However, they are inc"\
			<< "apable of coming to any significant conclusions." << std::endl;
}
