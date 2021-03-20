/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 17:02:39 by abaur             #+#    #+#             */
/*   Updated: 2021/03/20 19:09:51 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(unsigned population){
	this->population = population;
	this->horde = new Zombie[population];
}
ZombieHorde::~ZombieHorde(){
	delete []horde;
}

void	ZombieHorde::Announce(){
	for (unsigned i=0; i<this->population; i++)
		this->horde->Announce();
}


