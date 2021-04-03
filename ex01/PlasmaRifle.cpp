/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:56:06 by abaur             #+#    #+#             */
/*   Updated: 2021/04/03 14:42:39 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(void) 
: AWeapon("Plasma Rifle", 5, 21) {
}

PlasmaRifle::PlasmaRifle(const PlasmaRifle& other)
: AWeapon(other) {
}

PlasmaRifle::~PlasmaRifle() {
}

PlasmaRifle&	PlasmaRifle::operator =(const PlasmaRifle& other) {
	this->AWeapon::operator=(other);
	return *this;
}

void PlasmaRifle::attack() {
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
