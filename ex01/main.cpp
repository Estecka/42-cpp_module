/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 23:04:13 by abaur             #+#    #+#             */
/*   Updated: 2021/03/16 15:27:23 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

#include <iostream>
#include <stdlib.h>

extern int	main() {
	std::string	input;

	while (1) {
		std::cin >> input;
		if (input == "EXIT") {
			std::cout << "Sayonara mf" << std::endl;
			return EXIT_SUCCESS;
		} 
		else if (input == "ADD")
			std::cout << "I won't add no shit" << std::endl;
		else if (input == "SEARCH")
			std::cout << "Not in the mood rn" << std::endl;
		else
			std::cout << "Nani tf are you saying ?" << std::endl;
	}
}
