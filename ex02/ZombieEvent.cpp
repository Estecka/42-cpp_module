/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 20:34:54 by abaur             #+#    #+#             */
/*   Updated: 2021/03/19 20:48:27 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(){
	this->type = "fodder";
}
ZombieEvent::~ZombieEvent(){
	std::cout << "[debug] ZombieEvent" << type << "destroyed" << std::endl;
}

void	ZombieEvent::setZombieType(std::string type){
	this->type = type;
}

Zombie*	ZombieEvent::newZombie(std::string name){
	return new Zombie(name, this->type);
}

Zombie*	ZombieEvent::randomChump(){
	Zombie* zozo;
	std::string	name;

	name = std::to_string(rand() % 10000);
	name = std::string("0000").substr(0, 4-name.length()) + name;

	zozo = new Zombie(name, this->type);
	zozo->Announce();

	return zozo;
}
