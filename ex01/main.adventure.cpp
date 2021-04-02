/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.adventure.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:34:35 by abaur             #+#    #+#             */
/*   Updated: 2021/04/02 17:57:22 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"
#include "Character.hpp"
#include "Enemy.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"

#include <stdlib.h>

static void	EnemyTurn(Enemy*& enemy){
	if (!enemy && !(rand() % 3)) {
		std::cout << "Something is moving in the far." << std::endl;
		switch (rand() % 2) {
			default:
			case 0: enemy = new RadScorpion(); break;
			case 1: enemy = new SuperMutant(); break;
		}
		std::cout << "You spotted a " << enemy->getType() << "." << std::endl;
	}
	if (enemy)
		std::cout << "The " << enemy->getType() << " frolics happily through"\
			" the radioactive wastelands."
			<< std::endl;
}

static void Attack(Character& player, Enemy*& prey){
	if (!prey)
		std::cout << "The horizon is clear. There is nothing to hunt."\
			<< std::endl;
	else if (!player.getWeapon())
		std::cout << "It would be unwise to attack a " << prey->getType() \
			<< " bare-handed."\
			<< std::endl;
	else if (player.getAP() < player.getWeapon()->getAPCost())
		std::cout << "You are too tired to take this action."\
			<< std::endl;

	if (player.attack(prey))
		prey = NULL;
}

static void	Swap(Character& player){
	AWeapon* next = NULL;
	static int	i = 2;
	static AWeapon*	weapons[] = {
		new PlasmaRifle(),
		new PowerFist(),
		NULL,
	};

	i++;
	if (i > 2)
		i = 0;
	next = weapons[i];

	if (player.getWeapon())
		std::cout << "You put away your " << player.getWeapon()->getName() \
			<< "." << std::endl;
	if (next)
		std::cout << "You grab your trusty " << next->getName() << "."\
			<< std::endl;
	player.equip(next);
}

static void	FalloutAdventures(const std::string& name) {
	Character	player(name);
	Enemy*	prey = NULL;

	while (!std::cin.eof()){
		std::string	input;

		EnemyTurn(prey);
		std::cout << player \
			<< "[hint: exit, rest, atk, swap]" << std::endl 
			<< "> ";
		std::getline(std::cin, input);
		std::cout << std::endl;
	
		if (input == "exit")
			break;
		else if (input == "rest"){
			std::cout << "You take a well deserved rest." << std::endl;
			player.recoverAP();
		}
		else if (input == "atk") 
			Attack(player, prey);
		else if (input == "swap")
			Swap(player);
		else
			continue;
	}
}

extern int main(int argc, char** argv)
{
	const char*	name;

	if (argc <= 1)
		name = "Nameless Protagonist";
	else
		name = argv[1];

	srand(name[0]);
	FalloutAdventures(name);
}