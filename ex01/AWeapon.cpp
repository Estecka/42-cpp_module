/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:40:36 by abaur             #+#    #+#             */
/*   Updated: 2021/04/01 17:59:50 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

#include <exception>

AWeapon::AWeapon(void){
	throw std::invalid_argument("(void) constructor not supported.");
}
AWeapon::AWeapon(const AWeapon& other){
	*this = other;
}
AWeapon::AWeapon(const std::string& name, int apcost, int damage){
	this->name = name;
	this->apCost = apcost;
	this->damages = damage;
}
AWeapon::~AWeapon(){
}

AWeapon&	AWeapon::operator=(const AWeapon& other){
	this->name = other.name;
	this->damages = other.damages;
	this->apCost = other.apCost;
	return *this;
}

std::string	AWeapon::getName() const { return this->name; }
int	AWeapon::getDamage() const { return this->damages; }
int	AWeapon::getAPCost() const { return this->apCost;  }
