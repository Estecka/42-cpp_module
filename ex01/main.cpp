/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 23:04:13 by abaur             #+#    #+#             */
/*   Updated: 2021/03/16 22:10:54 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

#include <iostream>
#include <stdlib.h>

extern int	main() {
	std::string	input;

	std::cout << "Welcome to your completely trusty and definitely not suspisci\
ous phonebook. It's swell to finally meet your other friends." << std::endl;
	while (1) {
		std::cout << "> ";
		std::getline(std::cin, input);
		if (input == "EXIT") {
			std::cout << "Thank you for using the trial version of Phonebook®" \
				<< std::endl \
				<< "Please buy a license in order to recover your saved datas."\
				<< std::endl;
			return EXIT_SUCCESS;
		} 
		else if (input == "ADD")
			contact::Add();
		else if (input == "SEARCH")
			contact::Search();
		else if (input == "add" || input == "search" || input == "exit")
			std::cout << "Louder for those in the back." << std::endl;
		else if (input == "")
			;
		else
			std::cout << "You speak a fascinating language, but alas, I only he\
ar Latin." << std::endl;
	}
}
