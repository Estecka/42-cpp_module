/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main++.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:49:13 by abaur             #+#    #+#             */
/*   Updated: 2021/04/01 16:15:46 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "Noble.hpp"

extern int main(){
	Sorcerer* salazar = new Sorcerer("Salazar", "Breaker of the Great Marble");

	Victim* victim = new Victim("Test Subject #1498");
	Peon* peon = new Peon("Stanley");
	Noble* noble = new Noble("Barbara", "Ruler of the Great Marble");

	std::cout << *salazar;
	std::cout << *victim;
	std::cout << *peon;
	std::cout << *(Victim*)noble;

	salazar->polymorph(*victim);
	salazar->polymorph(*peon);
	salazar->polymorph(*noble);
	
	delete salazar;
	delete victim;
	delete peon;
	delete noble;
}