/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:54:42 by abaur             #+#    #+#             */
/*   Updated: 2021/03/21 18:12:17 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(float initialSmoothness){
	if (smoothness < 0)
		this->smoothness = 0;
	else if (smoothness > 1)
		this->smoothness = 1;
	else
		this->smoothness = initialSmoothness;
}
Brain::Brain(void){
	this->smoothness = 0.999f;
}
Brain::~Brain(){
}


float	Brain::GetSmoothness(){ return this->smoothness; }

float	Brain::Ponder(){
	smoothness *= smoothness;
	std::cout << "You ponder an intelligent thought. You brain becomes riper." << std::endl;
	return this->smoothness;
}

static char	GetHexDigit(unsigned value){
	if (value < 0xA)
		return '0' + value;
	else
		return 'A' + value - 0xA;
}

std::string	Brain::identify(){
	std::string	r = "";
	unsigned long	adress;

	adress = (unsigned long)this;
	do {
		r = GetHexDigit(adress % 0x10) + r;
		adress /= 0x10;
	} while(0 < adress);
	r = "0x" + r;
	return r;
}
