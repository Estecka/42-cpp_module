/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 15:24:52 by abaur             #+#    #+#             */
/*   Updated: 2021/04/03 18:50:59 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine(void) : ASpaceMarine() {
	std::cout << "Tactical Marine ready for battle!" << std::endl;
}
TacticalMarine::TacticalMarine(const TacticalMarine& other) : ASpaceMarine(other) {
	std::cout << "Tactical Marine ready for battle!" << std::endl;
}
TacticalMarine::~TacticalMarine(){
	std::cout << "Aaargh..." << std::endl;
}

TacticalMarine&	TacticalMarine::operator=(const TacticalMarine&other){
	this->ASpaceMarine::operator=(other);
	return *this;
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
