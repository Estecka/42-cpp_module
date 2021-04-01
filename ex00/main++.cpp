/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main++.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:49:13 by abaur             #+#    #+#             */
/*   Updated: 2021/04/01 15:38:55 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
// #include "King.hpp"

extern int main(){
	Sorcerer* salazar = new Sorcerer("Salazard", "Breaker of the Great Marble");

	Victim* victim = new Victim("Test Subject #1498");
	Peon* peon = new Peon("Stanley");

	std::cout << *salazar;
	std::cout << *victim;
	std::cout << *peon;

	salazar->polymorph(*victim);
	salazar->polymorph(*peon);
	
	delete salazar;
	delete victim;
	delete peon;
}