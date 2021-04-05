/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 22:39:57 by abaur             #+#    #+#             */
/*   Updated: 2021/04/05 16:01:11 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria(){
}
Ice::Ice(const Ice& other) : AMateria(other) {
}
Ice::~Ice(){
}

Ice&	Ice::operator=(const Ice& other) {
	this->AMateria::operator=(other);
	return *this;

}

AMateria*	Ice::clone() const{
	return new Ice(*this);
}

static const std::string	type = "ice";
const std::string&	Ice::type() const { return ::type; }

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	this->AMateria::use(target);
}

void	Ice::status() const {
	std::cout << "Ice  : ";
	this->AMateria::status();
}
