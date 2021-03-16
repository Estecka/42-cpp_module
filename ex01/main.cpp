/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 23:04:13 by abaur             #+#    #+#             */
/*   Updated: 2021/03/16 14:28:46 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

#include <iostream>
#include <stdlib.h>

static bool	strcmp(const char* s1, const char* s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return false;
		s1++;
		s2++;
	}
	return true;
}

extern int	main() {
	char buff[512];

	while (1) {
		std::cin >> buff;
		if (strcmp(buff, "EXIT")) {
			std::cout << "Sayonara mf" << std::endl;
			return EXIT_SUCCESS;
		} 
		else if (strcmp(buff, "ADD"))
			std::cout << "I won't add no shit" << std::endl;
		else if (strcmp(buff, "SEARCH"))
			std::cout << "Not in the mood rn" << std::endl;
		else
			std::cout << "Nani tf are you saying ?" << std::endl;
	}
}
