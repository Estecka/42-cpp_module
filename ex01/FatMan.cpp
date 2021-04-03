/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FatMan.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:34:00 by abaur             #+#    #+#             */
/*   Updated: 2021/04/03 14:47:23 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FatMan.hpp"

FatMan::FatMan(void)
: AWeapon("FatMan", 10, 0) {
	this->isLoaded = false;
}

FatMan::FatMan(const FatMan& other)
: AWeapon(other){
	*this = other;
}

FatMan::~FatMan(){
}

FatMan&	FatMan::operator =(const FatMan& other){
	this->AWeapon::operator=(other);
	this->isLoaded = other.isLoaded;
	return *this;
}

void	FatMan::attack(){
	if (this->isLoaded){
		this->isLoaded = false;
		this->apCost = 10;
		this->damages = 0;
		std::cout << "* tchack * * deafening blast *" << std::endl;
	}
	else {
		this->isLoaded = true;
		this->apCost = 5;
		this->damages = 9999;
		std::cout << "* click craaaack *" << std::endl
			<< "You reloaded the FatMan." << std::endl;
	}
}
