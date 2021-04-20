/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:01:36 by abaur             #+#    #+#             */
/*   Updated: 2021/04/20 22:33:24 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

#include <iostream>
#include <list>

void DumpList(std::list<int>& list) {
	std::cout << "list["<<list.size()<<"]{ ";
	for (
		std::list<int>::iterator it = list.begin();
		it != list.end();
		it++
	)
	{
		std::cout << *it << ", ";
	}
	std::cout << " }" << std::endl;
}

extern int	main()
{
	std::cout << "==== Initialization ====" << std::endl;
	MutantStack<int> source;
	std::list<int> list;
	for (int i=0; i<10; i++)
	{
		source.push(i);
		list.push_back(i);
	}
	std::stack<int> stack(source);
	MutantStack<int> result(stack);

	source.Dump();
	result.Dump();
	DumpList(list);

	std::cout << "==== Comparison ====" << std::endl;
	if (source == result) std::cout << "source == result" << std::endl;
	if (source == stack)  std::cout << "source == stack"  << std::endl;
	if (stack  == result) std::cout << "stack  == result" << std::endl;
		
	stack.push(0);
	if (stack != source) std::cout << "stack != source" << std::endl;
	if (stack != result) std::cout << "stack != result" << std::endl;

	std::cout << "==== Member methods ====" << std::endl;
	result.push(10);  list.push_back(10);
	result.Dump();    DumpList(list);
	result.pop();     list.pop_back();
	result.pop();     list.pop_back();
	result.Dump();    DumpList(list);
	result.push(11);  list.push_back(11);
	result.Dump();    DumpList(list);
	std::cout << result.size() << std::endl;  std::cout << list.size() << std::endl;
	std::cout << result.empty() << std::endl; std::cout << list.empty() << std::endl;
	std::cout << result.top() << std::endl;

	std::cout << "==== Iteration ====" << std::endl;
	for (
		MutantStack<int>::iterator it = result.begin();
		it != result.end();
		it++
	)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
