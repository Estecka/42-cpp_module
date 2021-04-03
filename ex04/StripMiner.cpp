/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StripMiner.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:23:24 by abaur             #+#    #+#             */
/*   Updated: 2021/04/04 00:15:12 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StripMiner.hpp"

StripMiner::StripMiner(void){
}
StripMiner::StripMiner(const StripMiner& other){
	*this = other;
}
StripMiner::~StripMiner(){
}

StripMiner&	StripMiner::operator=(const StripMiner& other){
	return *this;
}

std::string	StripMiner::getName() const { return "StripMiner"; }

std::string	StripMiner::mine(IAsteroid* target){
	std::string	result;

	if (target == NULL)
		result = "nothing";
	else
		result = target->beMined(this);

	std::cout << "* mining deep... got " << result << "! *" << std::endl;
	return result;
}
