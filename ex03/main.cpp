/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:17:17 by abaur             #+#    #+#             */
/*   Updated: 2021/03/20 19:54:48 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

#include <stdlib.h>
#include <string.h>

static void	ZombieApocalypse(const char* cityName){
	ZombieHorde*	horde;

	std::cout << "A new day rises on the lovely city of " << cityName << ". " \
		<< "Unfortunately, the city is prey to a terrible infection, " \
		<< "spreading amongst the citizens like the pest, and turning them int"\
		<< "o brainless Zombies." << std::endl << std::endl;
	horde = new ZombieHorde(10);
	horde->Announce();
	std::cout << std::endl \
		<< "There is only one hope for humanity to escape this nameless calami"\
		<< "ty: Nuclear Anihilation." << std::endl \
		<< "Will you press the big red button ? [y/n]" << std::endl;

	std::string	input;
	while(1) {
		std::cout << "> ";
		std::cin >> input;
		std::cout << std::endl;
		if (input == "yes" || input == "y")
			break;
		else
			std::cout << "You hesitate a moment. A drop of sweat runs along yo"\
				<< "ur temple. You try to think about alternative outcomes, bu"\
				<< "t nothing comes to mind. You have to find the resolve to p"\
				<< "ress this button." << std::endl;
	}
	std::cout << "You gather all your determination and press the button. "\
		<< cityName << " vanishes in a blinding flash of light." << std::endl;
	delete horde;
	std::cout << "A bittersweet tear escapes from your eye; " << cityName 
		<< " might be lost forever, but the world is saved." << std::endl;
}

extern int	main(int argc, char** argv){
	const char* name = "Citytown-ville";

	if (argc >= 2)
		name = argv[1];
	if (strlen(name) >= sizeof(int))
		srand(*(int*)name);
	ZombieApocalypse(name);
}