/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:04:45 by abaur             #+#    #+#             */
/*   Updated: 2021/04/17 18:19:27 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

#include <iostream>

const char*	alphabet = "abcdefghijklmnopqrstuvwxyz";
const int	decimals[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

void	Negate(const int& i){
	std::cout << -i << " ";
}

void	DumbToUpper(const char& c){
	std::cout << (char)(c + 'A' - 'a') << " ";
}

template <typename T>
void	PrintObject(T& obj) {
	std::cout << obj << " ";
}

extern int	main(){
	iter(alphabet, 26, &PrintObject); std::cout << std::endl;
	iter(alphabet, 26, &DumbToUpper); std::cout << std::endl;

	std::cout << std::showpos;
	iter(decimals, 10, &PrintObject); std::cout << std::endl;
	iter(decimals, 10, &Negate     ); std::cout << std::endl;
}
