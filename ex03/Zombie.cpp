/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 19:28:58 by abaur             #+#    #+#             */
/*   Updated: 2021/03/20 19:37:46 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <stdlib.h>

static std::string	RandomName(unsigned min, unsigned max){
	std::string	name = "";
	unsigned	size = min + (rand() % (max-min+1));

	for (unsigned i=0; i<size; i++)
		name += 'a' + (rand() % 26);
	name[0] += 'A' - 'a';
	return (name);
}

Zombie::Zombie(void) {
	this->name = RandomName(4, 10);
	this->type = "infected-citizen";
	// std::cout << "Another " << type << ", our dear " << name << ", was infecte"\
	// 	<< "d by the latest trending virus." << std::endl;
}

Zombie::~Zombie(){
	std::cout << this->name << " turned into dust and was scattered by th"\
		<< "e wind." << std::endl;
}


std::string	Zombie::GetName() { return this->name; }
std::string	Zombie::GetType() { return this->type; }
std::string	Zombie::GetMatricule() {
	std::string	type;

	type = this->type;
	for (unsigned i=0; i<type.length(); i++)
		if ('a' <= type[i] && type[i] <= 'z')
			type[i] += 'A' - 'a';
		
	return type + ": " + this->name;
}


void	Zombie::Announce(){
	std::cout << "<" << GetMatricule() << "> ";
	switch (rand() % 8)
	{
		default: std::cout << "My, what a fascinating sediment I just found laying right there !"; break;
		case 0:	std::cout << "The infection is not real !"; break;
		case 1:	std::cout << "* Coughs in your face *"; break;
		case 2:	std::cout << "Masks are usless !"; break;
		case 3:	std::cout << "BRainbrainbrainbrAin"; break;
		case 4:	std::cout << "* Regurgitates in zombie * "; break;
		case 5:	std::cout << "The Earth is fake, wake up !"; break;
		case 6:	std::cout << "I haven't washed my hands in years and I'm perfectly fine."; break;
		case 7:	std::cout << "Let's all gather in this very crowded place."; break;
	}
	std::cout << std::endl;
}
