/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 22:39:57 by abaur             #+#    #+#             */
/*   Updated: 2021/04/04 22:40:38 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria(){
	this->type = "ice";
}
Ice::Ice(const Ice& other) : AMateria(other) {
}
Ice::~Ice(){
}

Ice&	Ice::operator=(const Ice& other) {
	this->AMateria::operator=(other);
}

AMateria*	Ice::clone() const{
	return new Ice(*this);
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
