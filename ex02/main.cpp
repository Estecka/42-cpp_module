/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 21:00:27 by abaur             #+#    #+#             */
/*   Updated: 2021/03/19 23:19:00 by abaur            ###   ########.fr       */
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
	if (FindZombie(horde))
		std::cout << "The horde moves forward ominously." << std::endl;
	for (unsigned i=0; i<HORDEMAX; i++)
		if (horde[i])
			horde[i]->Announce();

	Zombie** empty = FindEmpty(horde);
	if (empty)
		*empty = builder->randomChump();

}
static void	Attack(Zombie* horde[HORDEMAX]){
	unsigned dice = rand() % 100;

	if (dice < 20) {
		std::cout << "You open your inner shakras, and temporarily becomes the"\
			<< " Hokage. You swiftly dash back and forth across the battlefie"\
			<< "ld, dealing a fatal strike to all who stand there." << std::endl;
		for (unsigned i=0; i<HORDEMAX; i++)
			if (horde[i]){
				delete horde[i];
				horde[i] = NULL;
			}
	}
	else if (dice < 45) {
		std::cout << "You pull a gatling gun out of your arse, and spray it ai"\
			<< "mlessly across the field." << std::endl;
		for (unsigned i=0; i<HORDEMAX; i++)
			if (horde[i] && (rand() % 3)){
				delete horde[i];
				horde[i] = NULL;
			}
	}
	else {
		std::cout << "You grab a fireaxe, and strike at the nearest zombie." << std::endl;
		Zombie** target = FindZombie(horde);
		if (target && !(rand() % 3)){
			delete *target;
			*target = NULL;
		}
		else
			std::cout << "You wave the axe around, but it fails to hit a target." << std::endl;
	}
};
static void	Defend(Zombie* horde[HORDEMAX]){
	Zombie** opponent = FindZombie(horde);

	if (opponent){
		(*opponent)->Announce();
		std::cout << "You dodge a bite at the very last moment." << std::endl;
	}
	else
		std::cout << "You take cover, and observe the laboratory from afar." << std ::endl;
};


static void	ZombieAdventures(const char* WillisName){
	Zombie	Willis = Zombie(WillisName, "friend");
	Zombie*	horde[HORDEMAX] = { NULL };
	ZombieEvent	builders[5];

	builders[0].setZombieType("fodder");
	builders[1].setZombieType("flyer");
	builders[2].setZombieType("spitter");
	builders[3].setZombieType("crawler");
	builders[4].setZombieType("dancer");

	Willis.Announce();
	std::cout << "Wait, this is not a zombie, this is your friend, " \
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
		std::cout << std::endl;
		if (input == "atk")
			Attack(horde);
		else if (input == "def")
			Defend(horde);
		else
			continue;
	}
	
	std::cout << WillisName << " finally reaches the van. You run back, and "\
		<< "take place into the conductor's seat. You trigger a remote deto"\
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
