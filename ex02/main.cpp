/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 21:00:27 by abaur             #+#    #+#             */
/*   Updated: 2021/03/19 21:55:54 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

#include <iostream>

void	Horde(){
	std::cout << "The horde does its thing." << std::endl;
}
void	Attack(){
	std::cout << "You attack !" << std::endl;
};
void	Defend(){
	std::cout << "You defend !" << std::endl;
};

static void	ZombieAdventures(const char* WillisName){
	Zombie	Willis = Zombie(WillisName, "friend");
	Zombie*	horde[10] = { NULL };
	unsigned int hordec = 0;
	std::string	input;

	Willis.Announce();
	std::cout << "But wait, this is not a zombie, this's your friend, " \
		<< WillisName << " ! They survived the initial explosion." << std::endl\
		<< WillisName << " is in a sorry state. More zombies are coming after "\
		<< "him. " << " You decide you will stay here and hold them back, until "\
		<< WillisName << " manages to reach the van." << std::endl;

	while (input != "esc")
	{
		Horde();
		std::cout << "> ";
		std::cin >> input;
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
