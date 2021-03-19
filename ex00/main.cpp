/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:09:35 by abaur             #+#    #+#             */
/*   Updated: 2021/03/19 01:29:33 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

#include <stdlib.h>
#include <time.h>

static void	PonyAdventuresTwoPointO(Pony *pony){
	pony->Walk();
	pony->Run();

	pony->Sleep();
	pony->Jump();
	pony->Walk();
	pony->Run();
	pony->Sleep();
	pony->Shine();
	pony->Transcend();

	pony->WakeUp();
	pony->Jump();
	pony->Walk();
	pony->Run();
	pony->Shine();
	pony->WakeUp();
	pony->Transcend();
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

	std::cout << "==== Pony on the Heap ====" << std::endl;
	PonyOnTheHeap(name, robe);
	std::cout << std::endl;

	std::cout << "==== Pony on the Stack ====" << std::endl;
	PonyOnTheStack(name, robe);
	std::cout << std::endl;
}
