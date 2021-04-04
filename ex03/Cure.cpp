/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 22:25:34 by abaur             #+#    #+#             */
/*   Updated: 2021/04/04 22:39:06 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria(){
	this->type = "cure";
}
Cure::Cure(const Cure& other) : AMateria(other) {
}
Cure::~Cure(){
}

Cure&	Cure::operator=(const Cure& other) {
	this->AMateria::operator=(other);
}

AMateria*	Cure::clone() const{
	return new Cure(*this);
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
