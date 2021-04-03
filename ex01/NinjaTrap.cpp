/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:14:11 by abaur             #+#    #+#             */
/*   Updated: 2021/04/03 14:31:46 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"
#include "stdlib.h"

NinjaTrap::NinjaTrap(void)
: Enemy(80, "N1NJ4-TP"){
	this->deathCry = "* beep KABOOM *";
	std::cout << "Let's get this party started !" << std::endl;
}

NinjaTrap::NinjaTrap(const NinjaTrap& other)
: Enemy(other) {
	std::cout << "Let's get this party started !" << std::endl;
}

NinjaTrap::~NinjaTrap(){
}

NinjaTrap&	NinjaTrap::operator =(const NinjaTrap& other){
	this->Enemy::operator=(other);
	return *this;
}

void	NinjaTrap::takeDamage(int dmgAmount){
	if (rand() % 2)
		this->Enemy::takeDamage(dmgAmount);
	else
		std::cout << "The N1NJ4-TP did a sick backwheel flip "
			"and dodged the hit !" << std::endl;
}
