/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:09:35 by abaur             #+#    #+#             */
/*   Updated: 2021/03/19 15:05:47 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

#include <stdlib.h>
#include <time.h>

#pragma clang diagnostic ignored "-Wunused-function"

static void	PonyAdventuresTwoPointO(Pony *pony){
	std::string	input;

	while (input != "exit")
	{
		std::cout << "> ";
		std::cin >> input;
		if (input == "sleep")
			pony->Sleep();
		else if (input == "wakeup")
			pony->WakeUp();
		else if (input == "walk")
			pony->Walk();
		else if (input == "run")
			pony->Run();
		else if (input == "jump")
			pony->Jump();
		else if (input == "shine")
			pony->Shine();
		else if (input == "transcend")
			pony->Transcend();
		else
			continue;
	}
}

static void	PonyOnTheHeap(std::string name, std::string colour){
	Pony*	pony = new Pony(name, colour);

	PonyAdventuresTwoPointO(pony);
	delete pony;
}

static void	PonyOnTheStack(std::string name, std::string colour){
	Pony	pony = Pony(name, colour);

	PonyAdventuresTwoPointO(&pony);
}

extern int	main(int argc, char** argv){
	std::string	name = "Johny the Default Pony";
	std::string	robe = "blank";

	srand(time(NULL));
	if (argc >= 2)
		name = argv[1];
	if (argc >= 3)
		robe = argv[2];

	
	std::cout << "[hint:] The available commands are: sleep, wakeup, walk, run"\
		<< ", jump, shine, transcend, and exit. You are free to use any of the"\
		<< "m, in any order, and in any context." << std::endl \
		<< "================" << std::endl << std::endl;

	std::cout << "==== Pony on the Heap ====" << std::endl;
	PonyOnTheHeap(name, robe);
	std::cout << std::endl;

	// std::cout << "==== Pony on the Stack ====" << std::endl;
	// PonyOnTheStack(name, robe);
	// std::cout << std::endl;
}
