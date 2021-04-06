/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 00:10:21 by abaur             #+#    #+#             */
/*   Updated: 2021/04/06 13:54:12 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiningBarge.hpp"

#include "Asteroid.hpp"
#include "Comet.hpp"
#include "DeepCoreMiner.hpp"
#include "Shop.hpp"
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
	std::cout << "You sell the materials for a total of " << worth << " imperial "\
		"credits." << std::endl;
	player.addMoney(worth);
	delete target;
}

static void Buy(MiningBarge& player){
	std::cout << "Select the product you wish to buy :" << std::endl;
	for (unsigned i=0; i<Shop::productCount; i++) {
		const IMiningLaser* product = Shop::products[i];
		std::cout \
			<< "["<<i<<"] " << product->getName() \
			<< " ($"<<product->getFullPrice()<<")"\
			<< std::endl;
	}

	unsigned i = getInt();
	if (i < 0 || Shop::productCount <= i)
		std::cout << "Operation cancelled" << std::endl;
	else 
	{
		if (player.getMoney() < Shop::products[i]->getFullPrice())
		{
			std::cout << "You don't have enough money to buy a "\
				<< Shop::products[i]->getName() << std::endl;
		}
		else 
		{
			IMiningLaser* item = Shop::products[i]->clone();
			player.addMoney(-item->getFullPrice());
			if (player.equip(item))
				std::cout << "You mount the " << item->getName() \
					<< " onto your ship " << std::endl;
			else {
				std::cout << "You realize you don't have enough room for your new "\
					"toy, so you throw it away." << std::endl;
				delete item;
			}
		}
	}
}

static void Sell(MiningBarge& player){
	std::cout << "Select a device to scrap :" << std::endl;
	for (unsigned i=0; i<player.getLaserCount(); i++)
		std::cout << "["<<i<<"] " << player.getLaser(i)->getName() << std::endl;

	unsigned i = getInt();
	if (0 <= i && i < player.getLaserCount())
	{
		IMiningLaser* item = player.unequip(i);
		std::cout << "You scrap your old " << item->getName() << " for a "\
			"reasonnable $" << Shop::Sell(*item) << "." << std::endl;
	}
	else
		std::cout << "Operation cancelled." << std::endl;
}

static void	SpaceMinerAdventures(int initialMoney){
	MiningBarge	player;
	player.addMoney(initialMoney);
	player.equip(new StripMiner());

	while(!std::cin.eof()) {
		std::string	input;

		std::cout \
			<< "You have " << player.getMoney() << " imperial Credits to your name." << std::endl \
			<< "[hint: exit, mine, buy, sell]" << std::endl \
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

extern int	main(int argc, char** argv){
	int	money;

	if (argc>1)
		money = atoi(argv[1]);
	else
		money = 1000;

	SpaceMinerAdventures(money);
}
