/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:30:21 by abaur             #+#    #+#             */
/*   Updated: 2021/03/21 19:35:33 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

#include <iostream>

HumanB::HumanB(const char* name){
	this->name = name;
	this->weapon = NULL;
}
HumanB::~HumanB(){}

void	HumanB::attack() {
	std::cout << name << " attacks with their " << weapon->GetType() << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon){
	this->weapon = &weapon;
}
