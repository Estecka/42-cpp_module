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

static void	FalloutAdventures(const char* name) {
	Character	player(name);
	Enemy*	prey;

	while (!std::cin.eof()){
		std::string	input;

		EnemyTurn(prey);
		std::cout << std::endl << player \
			<< "[hint: exit, rest, atk, swap]" << std::endl 
			<< "> ";
		std::getline(std::cin, input);
	
		if (input == "exit")
			break;
		else if (input == "rest")
			player.recoverAP();
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