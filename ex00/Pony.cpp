/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:08:58 by abaur             #+#    #+#             */
/*   Updated: 2021/03/18 19:27:58 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(void){
	this->name = "Johny the Default Pony";
	this->robeColor = "blank";

	this->isAlive = true;
	this->isAwake = true;

	this->distanceWalked = 0;
	this->legsBroken = 0;
}

Pony::Pony(std::string name, std::string robeColor) {
	this->name = name;
	this->robeColor = robeColor;

	this->isAlive = true;
	this->isAwake = true;

	this->distanceWalked = 0;
	this->legsBroken = 0;
}

Pony::~Pony(){
	std::cout << this->name << " was destroyed." << std::endl;
}
