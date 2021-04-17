/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:28:47 by abaur             #+#    #+#             */
/*   Updated: 2021/04/17 19:36:58 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#include <iostream>

extern int	main(){
	Array<char>	empty;
	Array<int>	decimals(10);
	for (size_t i=0; i<decimals.size(); i++)
		decimals[i] = i;

	Array<int>	negated;
	negated = decimals;

	for(size_t i=0; i<negated.size(); i++)
		negated[i] = -negated[i];

	std::cout << "empty";    empty.Dump();
	std::cout << "decimals"; decimals.Dump();
	std::cout << "negated";  negated.Dump();
}