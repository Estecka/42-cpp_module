/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:08:59 by abaur             #+#    #+#             */
/*   Updated: 2021/04/19 17:42:36 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <iostream>

template <typename T>
void	Test(T& container, int value){
	int i;

	try {
		i = easyfind<T>(container, value);
	}
	catch(const std::exception& e)
	{
		std::cout \
			<< "Could not find " << value \
			<< " (exception: " << e.what() << ")" << std::endl;
		return;
	}

	if (i < 0)
		std::cout \
			<< "Could not find " << value \
			<< " (returned " << i << ")" << std::endl;
	else
		std::cout << "Located " << value << " at index " << i << std::endl;
}

extern int	main(){
	std::vector<int>	vector(4, 0);
	std::list  <int>	list;

	for (std::size_t i=0; i<vector.size(); i++)
		vector[i] = 10 + i;
	for (std::size_t i=0; i<5;   i++)
		list.push_back(20 + i);

	std::cout << std::endl << "Vector" << std::endl;
	Test(vector,  9);
	Test(vector, 10);
	Test(vector, 11);
	Test(vector, 12);
	Test(vector, 13);
	Test(vector, 14);

	std::cout << std::endl << "List" << std::endl;
	Test(list, 19);
	Test(list, 21);
	Test(list, 22);
	Test(list, 23);
	Test(list, 24);
	Test(list, 25);
}
