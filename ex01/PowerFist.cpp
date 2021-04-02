/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:07:08 by abaur             #+#    #+#             */
/*   Updated: 2021/04/02 14:36:22 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

PowerFist::PowerFist(void) 
: AWeapon("Power Fist", 8, 50) {
}

PowerFist::PowerFist(const PowerFist& other)
: AWeapon(other) {
}

PowerFist::~PowerFist() {
}

PowerFist&	PowerFist::operator =(const PowerFist& other) {
	this->AWeapon::operator=(other);
	return *this;
}

void PowerFist::attack() const {
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
