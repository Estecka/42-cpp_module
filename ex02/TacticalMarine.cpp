/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:24:52 by abaur             #+#    #+#             */
/*   Updated: 2021/04/03 15:44:50 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"

#include <stdlib.h>

static unsigned	g_marineCount = 0;

static std::string randName(){
	switch (rand() % 6)
	{
		default: return "-Error";
		case 0: return "Alpha";
		case 1: return "Zoulou";
		case 2: return "Red";
		case 3: return "Blue";
		case 4: return "Viper";
		case 5: return "Sloth";
	}
}

TacticalMarine::TacticalMarine(void) {
	this->codeName = randName();
	this->uid = ++g_marineCount;
	std::cout << "Tactical Marine ready for battle!" << std::endl;
}
TacticalMarine::TacticalMarine(const TacticalMarine& other){
	*this = other;
	std::cout << "Tactical Marine ready for battle!" << std::endl;
}
TacticalMarine::~TacticalMarine(){
	std::cout << "Aaargh..." << std::endl;
}

TacticalMarine&	TacticalMarine::operator=(const TacticalMarine&other){
	this->codeName = other.codeName;
	this->uid = ++g_marineCount;
}

ISpaceMarine*	TacticalMarine::clone() const {
	return new TacticalMarine(*this);
}

void	TacticalMarine::battleCry() const {
	std::cout << "For the holy PLOT!" << std::endl;
}
void	TacticalMarine::rangedAttack() const {
	std::cout << "* attacks with a bolter *" << std::endl;
}
void	TacticalMarine::meleeAttack() const {
	std::cout << "* attacks with a chainsword *" << std::endl;
}

void	TacticalMarine::report() const {
	std::cout << this->codeName << "-" << this->uid << ", "\
		"reporting for duty !"\
		<< std::endl;
}
