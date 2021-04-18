/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:28:47 by abaur             #+#    #+#             */
/*   Updated: 2021/04/18 16:50:00 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#include <iostream>

extern int	main(){
	Array<char>	empty;
	Array<int>	decimals(10);
	Array<int>*	negated;

	std::cout << "empty ";    empty.Dump();

	for (size_t i=0; i<decimals.size(); i++)
		decimals[i] = i;
	std::cout << "decimals                      "; decimals.Dump();

	negated = new Array<int>(decimals);
	std::cout << "negated  (before assignation) "; negated->Dump();
	for(size_t i=0; i<negated->size(); i++)
		(*negated)[i] = -(*negated)[i];
	std::cout << "negated  (after assignation)  "; negated->Dump();
	std::cout << "decimals (after negated)      "; decimals.Dump();

	delete negated;
}