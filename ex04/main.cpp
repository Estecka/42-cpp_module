/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 00:10:21 by abaur             #+#    #+#             */
/*   Updated: 2021/04/04 03:05:34 by abaur            ###   ########.fr       */
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

static void Mine(MiningBarge& player){
}
static void Buy(MiningBarge& player){
}
static void Sell(MiningBarge& player){
	std::cout << "Select a device to scrap :" << std::endl;
	for (unsigned i=0; i<player.getLaserCount(); i++)
		std::cout << "["<<i<<"] " << player.getLaser(i)->getName() << std::endl;

	unsigned	i;
	std::cout << "> ";
	std::cin >> i;
	std::cout << std::endl;
	if (!std::cin.fail() && 0 <= i && i < player.getLaserCount()){
		IMiningLaser* item = player.unequip(i);
		std::cout << "You scrap your old " << item->getName() << " for a "\
			"reasonnable price." << std::endl;
		delete item;
	}
	else {
		std::cout << "Operation cancelled." << std::endl;
		std::cin.clear();
	}
	std::cin.ignore(STREAM_MAX, '\n');
}

static void	SpaceMinerAdventures(){
	MiningBarge	player;
	player.equip(new StripMiner());

	while(!std::cin.eof()) {
		std::string	input;

		std::cout << "[hint: exit, mine, buy, sell]" << std::endl \
			<< "> " << std::endl;
		std::getline(std::cin, input);
		std::cout << std::endl;

		if (input == "exit")
			break;
		else if (input == "mine")
			Mine(player);
		else if (input == "buy")
			Buy(player);
		else if (input == "sell")
			Sell(player);
		else
			continue;
	}
}

extern int	main(){
	SpaceMinerAdventures();
}
