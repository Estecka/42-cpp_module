/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DeepCoreMiner.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:15:29 by abaur             #+#    #+#             */
/*   Updated: 2021/04/05 17:40:09 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DeepCoreMiner.hpp"

DeepCoreMiner::DeepCoreMiner(void){
	this->durability = 10;
}
DeepCoreMiner::DeepCoreMiner(const DeepCoreMiner& other){
	*this = other;
}
DeepCoreMiner::~DeepCoreMiner(){
}

DeepCoreMiner&	DeepCoreMiner::operator=(const DeepCoreMiner& other){
	(void)other;
	return *this;
}

std::string	DeepCoreMiner::getName() const { return "DeepCoreMiner"; }
int	DeepCoreMiner::getDurability() const { return this->durability;}
int	DeepCoreMiner::getFullPrice() const { return 5000; }
int	DeepCoreMiner::getWorth() const { return getFullPrice() * this->durability / 20; }

std::string	DeepCoreMiner::mine(IAsteroid* target){
	std::string	result;

	if (target == NULL)
		result = "nothing";
	else
		result = target->beMined(this);

	std::cout << "* mining deep... got " << result << "! *" << std::endl;
	return result;
}
