/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DeepCoreMiner.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:15:29 by abaur             #+#    #+#             */
/*   Updated: 2021/04/06 14:16:02 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DeepCoreMiner.hpp"

DeepCoreMiner::DeepCoreMiner(void){
	this->durability = this->getDurabilityMax();
}
DeepCoreMiner::DeepCoreMiner(const DeepCoreMiner& other){
	*this = other;
}
DeepCoreMiner::~DeepCoreMiner(){
}

DeepCoreMiner&	DeepCoreMiner::operator=(const DeepCoreMiner& other){
	this->durability = other.durability;
	return *this;
}

std::string	DeepCoreMiner::getName() const { return "DeepCoreMiner"; }
int	DeepCoreMiner::getDurability() const { return this->durability;}
int	DeepCoreMiner::getDurabilityMax() const { return 10; }
int	DeepCoreMiner::getFullPrice() const { return 5000; }

std::string	DeepCoreMiner::mine(IAsteroid* target){
	std::string	result = "nothing";

	if (this->durability <= 0)
		std::cout << "* This mining equipement is broken and cannot operate. *"\
			<< std::endl;
	else if (target == NULL)
		std::cout << "*There is nothing to mine.*" << std::endl;
	else {
		result = target->beMined(this);
		std::cout << "* mining deep... got " << result << "! *" << std::endl;
		this->durability--;
	}

	return result;
}

IMiningLaser*	DeepCoreMiner::clone() const {
	return new DeepCoreMiner(*this);
}
