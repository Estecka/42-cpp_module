/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroid.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:31:58 by abaur             #+#    #+#             */
/*   Updated: 2021/04/03 23:36:22 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Asteroid.hpp"

Asteroid::Asteroid(void){
}
Asteroid::Asteroid(const Asteroid& other){
	*this = other;
}
Asteroid::~Asteroid(){
}
Asteroid&	Asteroid::operator=(const Asteroid& other){
	return *this;
}

std::string	Asteroid::getName() const { return "Asteroid"; }

std::string	Asteroid::beMined(const StripMiner* miner) const    { return "Flavium"; }
std::string	Asteroid::beMined(const DeepCoreMiner* miner) const { return "Dragonite"; }
