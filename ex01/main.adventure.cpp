#include "AWeapon.hpp"
#include "Character.hpp"
#include "Enemy.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"

static void	EnemyTurn(Enemy*& enemy){
	(void)enemy;
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

static void	FalloutAdventures(const std::string& name) {
	Character	player(name);
	Enemy*	prey = NULL;

	while (!std::cin.eof()){
		std::string	input;

		EnemyTurn(prey);
		std::cout << std::endl << player \
			<< "[hint: exit, rest, atk, swap]" << std::endl 
			<< "> ";
		std::getline(std::cin, input);
	
		if (input == "exit")
			break;
		else if (input == "rest"){
			std::cout << "You take a well deserved rest." << std::endl;
			player.recoverAP();
		}
		else if (input == "atk") 
			Attack(player, prey);
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

	FalloutAdventures(name);
}