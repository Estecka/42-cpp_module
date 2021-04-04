/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Amateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 19:31:49 by abaur             #+#    #+#             */
/*   Updated: 2021/04/04 20:55:39 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#include <exception>

AMateria::AMateria(void){
	throw std::invalid_argument("AMateria(void) not supported");
}
AMateria::AMateria(const AMateria& other){
	*this = other;
}
AMateria::~AMateria(){
}

AMateria&	AMateria::operator=(const AMateria& other){
	this->type = other.type;
	this->_xp = other._xp;
}

const std::string&	AMateria::getType() const { return (this->type); }
unsigned int	AMateria::getXP() const { return this->_xp; }
