/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:09:35 by abaur             #+#    #+#             */
/*   Updated: 2021/03/19 01:05:27 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

#include <stdlib.h>
#include <time.h>

static void	PonyAdventuresTwoPointO(Pony *pony){
	pony->WakeUp();
	pony->Jump();
	pony->Walk();
	pony->Run();
	pony->Shine();
	pony->Transcend();

	pony->Sleep();
	pony->Sleep();
	pony->Jump();
	pony->Walk();
	pony->Run();
	pony->Shine();
	pony->Transcend();
}

static void	PonyOnTheHeap(){
	Pony	*pony = new Pony();

	std::cout << "==== Pony on the Heap ====" << std::endl;
	PonyAdventuresTwoPointO(pony);
	delete pony;
	std::cout << std::endl;
}

static void	PonyOnTheStack(){
	Pony	pony;

	std::cout << "==== Pony on the Stack ====" << std::endl;
	PonyAdventuresTwoPointO(&pony);
	std::cout << std::endl;
}

extern int	main(){
	srand(time(NULL));

	PonyOnTheHeap();
	PonyOnTheStack();
}
