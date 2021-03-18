/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:09:35 by abaur             #+#    #+#             */
/*   Updated: 2021/03/18 22:47:28 by abaur            ###   ########.fr       */
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
	Pony	*pony;

	(void)pony;
	// PonyAdventuresTwoPointO(pony);
}

static void	PonyOnTheStack(){
	Pony	pony;

	PonyAdventuresTwoPointO(&pony);
}

extern int	main(){
	srand(time(NULL));

	PonyOnTheHeap();
	PonyOnTheStack();
}
