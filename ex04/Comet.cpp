/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Comet.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:31:58 by abaur             #+#    #+#             */
/*   Updated: 2021/04/03 23:36:58 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Comet.hpp"

Comet::Comet(void){
}
Comet::Comet(const Comet& other){
	*this = other;
}
Comet::~Comet(){
}
Comet&	Comet::operator=(const Comet& other){
	return *this;
}

std::string	Comet::getName() const { return "Comet"; }

std::string	Comet::beMined(const StripMiner* miner) const    { return "Tartarite"; }
std::string	Comet::beMined(const DeepCoreMiner* miner) const { return "Meium"; }
