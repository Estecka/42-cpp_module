/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 00:10:21 by abaur             #+#    #+#             */
/*   Updated: 2021/04/04 03:56:50 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiningBarge.hpp"

#include "Asteroid.hpp"
#include "Comet.hpp"
#include "DeepCoreMiner.hpp"
#include "StripMiner.hpp"

#include <iostream>
#include <limits>
#include <stdlib.h>

#define STREAM_MAX	(std::numeric_limits<std::streamsize>::max())

#pragma clang diagnostic ignored "-Wunused-parameter"

static unsigned	getInt(){
	unsigned	i;

	std::cout << "> ";
	std::cin >> i;
	std::cout << std::endl;
	if (std::cin.fail()) {
		std::cin.clear();
		i = -1;
	}
	std::cin.ignore(STREAM_MAX, '\n');

	return i;
}

static void Mine(MiningBarge& player){
	IAsteroid*	target;

	switch (rand() % 4)
	{
		default: target = new Asteroid(); break;
		case 0:  target = new Comet();    break;
	}

	std::cout << "After traveling for a while, you stumble upon a " \
		<< target->getName() << ", and proceed to harvest its content."\
		<< std::endl;

	int worth = player.mine(target);
	std::cout << "You sell the material for a total of " << worth << " imperial "\
		"credits." << std::endl;
	delete target;
}

static void Buy(MiningBarge& player){
	std::cout << "Select the product you wish to buy :" << std::endl \
		<< "[0] Strip Miner" << std::endl \
		<< "[1] DeepCore Miner" << std::endl \
		;

	unsigned i = getInt();
	IMiningLaser* item;
	switch (i)
	{
		default: item = NULL; break;
		case 0: item = new StripMiner(); break;
		case 1: item = new DeepCoreMiner(); break;
	}

	if (item){
		if (player.equip(item))
			std::cout << "You mount the " << item->getName() \
				<< " onto your ship " << std::endl;
		else {
			std::cout << "You realize you don't have enough room for your new "\
				"toy, so you throw it away." << std::endl;
			delete item;
		}
	}
	else
		std::cout << "Operation cancelled" << std::endl;
}

static void Sell(MiningBarge& player){
	std::cout << "Select a device to scrap :" << std::endl;
	for (unsigned i=0; i<player.getLaserCount(); i++)
		std::cout << "["<<i<<"] " << player.getLaser(i)->getName() << std::endl;

	unsigned i = getInt();
	if (0 <= i && i < player.getLaserCount()){
		IMiningLaser* item = player.unequip(i);
		std::cout << "You scrap your old " << item->getName() << " for a "\
			"reasonnable price." << std::endl;
		delete item;
	}
	else
		std::cout << "Operation cancelled." << std::endl;
}

static void	SpaceMinerAdventures(){
	MiningBarge	player;
	player.equip(new StripMiner());

	while(!std::cin.eof()) {
		std::string	input;

		std::cout << "[hint: exit, mine, buy, sell]" << std::endl \
			<< "> ";
		std::getline(std::cin, input);
		std::cout << std::endl;

		if (input == "exit")
			break;
		else if (input == "mine")
			Mine(player);
		else if (input == "buy")
			Buy(player);
		else if (input == "sell")
		{
			if (player.getLaserCount() > 1)
				Sell(player);
			else
				std::cout << "You don't have any spare equipement you can afford "\
					"to sell away." << std::endl;
		}
		else
			continue;
	}
}

extern int	main(){
	SpaceMinerAdventures();
}
