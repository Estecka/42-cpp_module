/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StripMiner.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:23:24 by abaur             #+#    #+#             */
/*   Updated: 2021/04/03 23:25:41 by abaur            ###   ########.fr       */
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

std::string	StripMiner::getName() { return "StripMiner"; }

std::string	StripMiner::mine(IAsteroid* target){
	return target->beMined(this);
}
