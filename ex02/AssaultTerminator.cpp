/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:55:28 by abaur             #+#    #+#             */
/*   Updated: 2021/04/03 17:03:22 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"

#include <iostream>

AssaultTerminator::AssaultTerminator(void) {
	std::cout << "* teleports from space *" << std::endl;
}
AssaultTerminator::AssaultTerminator(const AssaultTerminator& other){
	*this = other;
	std::cout << "* teleports from space *" << std::endl;
}
AssaultTerminator::~AssaultTerminator(){
	std::cout << "I'll be back..." << std::endl;
}

AssaultTerminator&	AssaultTerminator::operator=(const AssaultTerminator& other){
}

ISpaceMarine*	AssaultTerminator::clone() const {
	return new AssaultTerminator(*this);
}

void	AssaultTerminator::battleCry() const {
	std::cout << "This code is unclean. PURIFY IT!" << std::endl;
}
void	AssaultTerminator::rangedAttack() const {
	std::cout << "* does nothing *" << std::endl;
}
void	AssaultTerminator::battleCry() const {
	std::cout << "* attacks with chainfists *" << std::endl;
}

void	AssaultTerminator::report() const {
}