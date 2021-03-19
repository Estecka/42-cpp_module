/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 21:00:27 by abaur             #+#    #+#             */
/*   Updated: 2021/03/19 22:37:34 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

#include <iostream>
#include <stdlib.h>

#define HORDEMAX	10

static Zombie**	FindEmpty(Zombie* horde[HORDEMAX]){
	for (unsigned i=0; i<HORDEMAX; i++)
		if (!horde[i])
			return &horde[i];
	return NULL;
}
static Zombie**	FindZombie(Zombie* horde[HORDEMAX]){
	for (unsigned i=0; i<HORDEMAX; i++)
		if (horde[i])
			return &horde[i];
	return NULL;
}


static void	Horde(Zombie* horde[HORDEMAX], ZombieEvent* builder){
	Zombie**	empty;

	empty = FindEmpty(horde);
	if (empty) {
		*empty = builder->randomChump();
	}

	std::cout << "The horde moves forward ominously." << std::endl;
	for (unsigned i=0; i<HORDEMAX; i++)
		if (horde[i])
			horde[i]->Announce();
}
static void	Attack(){
	std::cout << "You attack !" << std::endl;
};
static void	Defend(){
	std::cout << "You take cover. Dodging an attack at the last moment." << std::endl;
};


static void	ZombieAdventures(const char* WillisName){
	Zombie	Willis = Zombie(WillisName, "friend");
	Zombie*	horde[HORDEMAX] = { NULL };
	ZombieEvent	builders[5];

	builders[0].setZombieType("fodder");
	builders[1].setZombieType("flying");
	builders[2].setZombieType("spitter");
	builders[3].setZombieType("crawler");
	builders[4].setZombieType("dancer");

	Willis.Announce();
	std::cout << "But wait, this is not a zombie, this is your friend, " \
		<< WillisName << " ! They survived the initial explosion." << std::endl\
		<< WillisName << " is in a sorry state. More zombies are coming after "\
		<< "them. You decide you will stay here, and hold them back until "\
		<< WillisName << " manages to reach the van." << std::endl;

	std::string	input;
	while (input != "esc")
	{
		Horde(horde, &builders[rand() % 5]);
		std::cout << "> ";
		std::cin >> input;
		std::cout << "\x1B[2J\x1B[H"; // Clears the terminal
		if (input == "atk")
			Attack();
		else if (input == "def")
			Defend();
		else
			continue;
	}
	
	std::cout << WillisName << " finally reaches the van. You run back to it a"\
		<< "nd take place into the conductor's seat. You trigger a remote deto"\
		<< "nator, blowing the remains of the laboratory to smithereens, along"\
		<< " with the remaining zombies." << std::endl;
	for (int i=0; i<10; i++)
		if (horde[i])
			delete horde[i];
	std::cout << "You safely drive away with your good mate " << WillisName \
		<< ", but as you look back to see how they fare, you see that ";
}

extern int	main(int argc, char** argv){
	const char*	name = "Willis";

	if (argc >= 2)
		name = argv[1];

	std::cout << "[hint:] The available commands are:" << std::endl \
		<< "atk (Attack), def (Defend), and esc (Escape)." << std::endl \
		<< "================" << std::endl << std::endl;
	ZombieAdventures(name);
	std::cout << "As it turns out, they were infected all along." << std::endl;
}
