/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:19:21 by abaur             #+#    #+#             */
/*   Updated: 2021/03/21 19:30:05 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const char* type){
	this->type = type;
}
Weapon::~Weapon(){}

void	Weapon::setType(const char* type){ this->type = type; }
const char*	Weapon::GetType(void) const { return this->type; }
