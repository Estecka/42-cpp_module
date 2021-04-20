/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:55:32 by abaur             #+#    #+#             */
/*   Updated: 2021/04/20 15:43:21 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iostream>
#include <vector>

#define CHEAPC	6
const int	cheapMyriades[CHEAPC] = { -2000000000, 2, -3, 2000000000, -3, 128, };

template <typename IT>
static void tryAdd(Span& span, const IT& begin, const IT&end) {
	try 
	{
		span.addNumber(begin, end);
	} 
	catch (const std::exception& e)
	{
		std::cout << "Caught Exception : " << e.what() << std::endl;
	}
}

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


	std::cout << std::endl << "==== Iterator tests ===="  << std::endl;
	Span	iteratron(100);

	std::cout << std::endl << "== int* =="  << std::endl;
	iteratron.addNumber<const int*>(cheapMyriades + 0, cheapMyriades + CHEAPC);
	iteratron.Dump();
	tryAdd<const int*>(iteratron, cheapMyriades+CHEAPC, cheapMyriades+0);
	iteratron.Dump();
	tryAdd<const int*>(iteratron, cheapMyriades+0, cheapMyriades+1000);
	iteratron.Dump();

	std::cout << std::endl << "== vector<int>::iterator =="  << std::endl;
	std::vector<int> src(3);
	std::vector<int> unlimitedpower(1000);
	iteratron.addNumber(src.begin(), src.end());
	iteratron.Dump();
	tryAdd(iteratron, src.end(), src.begin());
	iteratron.Dump();
	tryAdd(iteratron, unlimitedpower.begin(), unlimitedpower.end());
	iteratron.Dump();
}
