/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroid.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:31:58 by abaur             #+#    #+#             */
/*   Updated: 2021/04/04 00:33:01 by abaur            ###   ########.fr       */
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
	(void)other;
	return *this;
}

std::string	Asteroid::getName() const { return "Asteroid"; }

std::string	Asteroid::beMined(const StripMiner* miner) const    { (void)miner; return "Flavium"; }
std::string	Asteroid::beMined(const DeepCoreMiner* miner) const { (void)miner; return "Dragonite"; }
