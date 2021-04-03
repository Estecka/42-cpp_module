/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 00:10:21 by abaur             #+#    #+#             */
/*   Updated: 2021/04/04 00:31:17 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiningBarge.hpp"

#include "Asteroid.hpp"
#include "Comet.hpp"
#include "DeepCoreMiner.hpp"
#include "StripMiner.hpp"

#include <iostream>
#include <stdlib.h>

#pragma clang diagnostic ignored "-Wunused-parameter"

static void Mine(MiningBarge& player){
}
static void Buy(MiningBarge& player){
}
static void Sell(MiningBarge& player){
}

static void	SpaceMinerAdventures(){
	MiningBarge	player;
	player.equip(new StripMiner());

	while(!std::cout.eof()) {
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
