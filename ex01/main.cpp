/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:55:32 by abaur             #+#    #+#             */
/*   Updated: 2021/04/19 19:26:38 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iostream>

#define CHEAPC	6
const int	cheapMyriades[CHEAPC] = { -2000000000, 2, -3, 2000000000, -3, 128, };

extern int	main() {
	Span	decimals(10);
	Span	myriades(10000);

	for (size_t i=0; i<decimals.cap(); i++)
		decimals.addNumber(i);
	for (size_t i=0; i<myriades.cap(); i++)
		myriades.addNumber(cheapMyriades[i % CHEAPC]);

	std::cout << decimals.shortestSpan() << std::endl;
	std::cout << decimals.longestSpan()  << std::endl;
	std::cout << myriades.shortestSpan() << std::endl;
	std::cout << myriades.longestSpan()  << std::endl;
}
