/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:01:36 by abaur             #+#    #+#             */
/*   Updated: 2021/04/20 22:18:23 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

#include <iostream>

extern int	main()
{
	std::cout << "==== Initialization ====" << std::endl;
	MutantStack<int> source;
	for (int i=0; i<10; i++)
		source.push(i);
	std::stack<int> stack(source);
	MutantStack<int> result(stack);

	source.Dump();
	result.Dump();

	std::cout << "==== Comparison ====" << std::endl;
	if (source == result) std::cout << "source == result" << std::endl;
	if (source == stack)  std::cout << "source == stack"  << std::endl;
	if (stack  == result) std::cout << "stack  == result" << std::endl;
		
	stack.push(0);
	if (stack != source) std::cout << "stack != source" << std::endl;
	if (stack != result) std::cout << "stack != result" << std::endl;

	std::cout << "==== Member methods ====" << std::endl;
	result.push(10);
	result.Dump();
	result.pop();
	result.pop();
	result.Dump();
	result.push(11);
	result.Dump();
	std::cout << result.size() << std::endl;
	std::cout << result.top() << std::endl;
	std::cout << result.empty() << std::endl;

	std::cout << "==== Iteration ====" << std::endl;
	for (
		MutantStack<int>::iterator it = result.begin();
		it < result.end();
		it++
	)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
