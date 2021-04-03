/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpaceMarine.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 17:15:32 by abaur             #+#    #+#             */
/*   Updated: 2021/04/03 17:17:30 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpaceMarine.hpp"

#include <stdlib.h>

static unsigned	g_marineCount = 0;

static std::string randName(){
	switch (rand() % 6)
	{
		default: return "-Error";
		case 0: return "Alpha";
		case 1: return "Zoulou";
		case 2: return "Red";
		case 3: return "Blue";
		case 4: return "Viper";
		case 5: return "Sloth";
	}
}

ASpaceMarine::ASpaceMarine(void) {
	this->codeName = randName();
	this->uid = ++g_marineCount;
}
ASpaceMarine::ASpaceMarine(const ASpaceMarine& other){
	*this = other;
}
ASpaceMarine::~ASpaceMarine(){
}

ASpaceMarine&	ASpaceMarine::operator=(const ASpaceMarine&other){
	this->codeName = other.codeName;
	this->uid = ++g_marineCount;
}
