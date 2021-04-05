/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StripMiner.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:23:24 by abaur             #+#    #+#             */
/*   Updated: 2021/04/05 17:40:15 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StripMiner.hpp"

StripMiner::StripMiner(void){
	this->durability = 20;
}
StripMiner::StripMiner(const StripMiner& other){
	*this = other;
}
StripMiner::~StripMiner(){
}

StripMiner&	StripMiner::operator=(const StripMiner& other){
	(void)other;
	return *this;
}

std::string	StripMiner::getName() const { return "StripMiner"; }
int	StripMiner::getDurability() const { return this->durability;}
int	StripMiner::getFullPrice() const { return 1000; }
int	StripMiner::getWorth() const { return getFullPrice() * this->durability / 40; }

std::string	StripMiner::mine(IAsteroid* target){
	std::string	result;

	if (target == NULL)
		result = "nothing";
	else
		result = target->beMined(this);

	std::cout << "* strip mining... got " << result << "! *" << std::endl;
	return result;
}
