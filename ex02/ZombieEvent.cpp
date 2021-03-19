/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 20:34:54 by abaur             #+#    #+#             */
/*   Updated: 2021/03/19 21:09:37 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

#include <stdlib.h>

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
	int     id;
	char    name[5];

	id = rand() % 10000;
	for (int i=3; i >= 0; i--){
		name[i] = '0' + id % 10;
		id /= 10;
	}
	name[4] = '\0';

	zozo = new Zombie(name, this->type);
	zozo->Announce();

	return zozo;
}
