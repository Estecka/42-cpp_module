/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 19:28:58 by abaur             #+#    #+#             */
/*   Updated: 2021/03/19 20:59:39 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

Zombie::Zombie(std::string name, std::string type) {
	this->name = name;
	this->type = type;
	std::cout << "A new Zombie, " << GetMatricule() << ", emerges from the rad"\
		<< "ioactive wastes of the old laboratory." << std::endl;
}

Zombie::~Zombie(){
	std::cout << GetMatricule() << " turns back into dust." \
		<< " It will not be remembered." << std::endl;
}


std::string	Zombie::GetName() { return this->name; }
std::string	Zombie::GetType() { return this->type; }
std::string	Zombie::GetMatricule() {
	std::string	type;

	type = this->type.substr(0, 6);
	for (unsigned i=0; i<type.length(); i++)
		if ('a' <= type[i] || type[i] <= 'a')
			type[i] += 'A' - 'a';
		
	return type.substr(0, 6) + "-" + this->name;
}


void	Zombie::Announce(){
	std::cout << "<" << GetMatricule() << "> ";
	switch (rand() % 4)
	{
		default: std::cout << "My, what a fascinating sediment I just found laying right there !"; break;
		case 0:	std::cout << "Baaaaaah,.."; break;
		case 1:	std::cout << "RrrrRrrRRh !"; break;
		case 2:	std::cout << "Guuuuuuuuuh..."; break;
		case 3:	std::cout << "BRainbrainbrainbrAin"; break;
	}
	std::cout << std::endl;
}
