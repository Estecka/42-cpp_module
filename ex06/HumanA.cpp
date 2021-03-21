/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:22:05 by abaur             #+#    #+#             */
/*   Updated: 2021/03/21 19:34:22 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

#include <iostream>

HumanA::HumanA(const char* name, Weapon& weaponRef) : weapon(weaponRef) {
	this->name = name;
}
HumanA::~HumanA(){};

void	HumanA::attack(){
	std::cout << name << " attacks with their " << weapon.GetType() << std::endl;
}
