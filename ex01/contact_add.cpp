/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact_add.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:20:55 by abaur             #+#    #+#             */
/*   Updated: 2021/03/16 18:54:38 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

#include <iostream>

#define BOLD(s)	"\e[1m" << s << "\e[0m"

void	contact::Add(){
	if (ccount >= 8)
	{
		std::cout << "Thank you, but I'm not hungry anymore." << std::endl \
			<< "Come back tomorrow with more sacrifices." << std::endl;
		return;
	}

	std::cout << "This will be your " << (ccount+1) << "th contact" << std::endl\
		<< "Please enter a lovely " << BOLD("Name") << " :" << std::endl;
	getline(std::cin, contact::clist[ccount].firstName);

	std::cout << "What a lovely name. What would their " << BOLD("Last Name") \
		<< " be ?" << std::endl;
	getline(std::cin, contact::clist[ccount].lastName);

	std::cout << "Despicable. Let's find them an ugly " << BOLD("Nickname") \
		<< "." << std::endl;
	getline(std::cin, contact::clist[ccount].nickName);

	std::cout << "Laughable. What's their " << BOLD("Login") << " ?" \
		<< std::endl;
	getline(std::cin, contact::clist[ccount].login);

	std::cout << "And their passw... uh, I mean " << BOLD("Postal Adress") \
		<< " ?" << std::endl;
	getline(std::cin, contact::clist[ccount].postalAdress);

	std::cout << "It would be a shame if they were to receive junk mail there."\
		<< std::endl \
		<< "What about their " << BOLD("Email Adress") << " ?" << std::endl;
	getline(std::cin, contact::clist[ccount].emailAdress);

	std::cout << "Nowadays, junk mail even comes in electronic form." \
	<< std::endl \
	<< "What's their " << BOLD("Phone Number") << " ?" << std::endl;
	getline(std::cin, contact::clist[ccount].phoneNumber);

	std::cout << "Junk even comes through the phone sometimes. \
Nowadays you can't tell anything to anyone without getting spammed. u_u" \
	<< std::endl \
	<< "By the way, when's their " << BOLD("Birthday") << " ?" << std::endl;
	getline(std::cin, contact::clist[ccount].birthdayDate);

	std::cout << "Hopefully they'll live to see the next one." << std::endl \
		<< "What's their " << BOLD("Favorite Meal") \
		<< " then ? It's for... a cake." << std::endl;
	getline(std::cin, contact::clist[ccount].favoriteMeal);

	std::cout << "Adequate." << std::endl \
		<< "Now we get to the important part. What's the " << BOLD("Color") \
		<< " of their " << BOLD("Underwear") << " ? owo" << std::endl;
	getline(std::cin, contact::clist[ccount].underwearColor);

	std::cout << "Last but not least; tell me about their " \
		<< BOLD("Darkest Secret") << " !" << std::endl;
	getline(std::cin, contact::clist[ccount].darkestSecret);


	std::cout << "Thank you for your contribution. The " << BOLD("sacrifice") \
		<< " has been acknowledged." << std::endl;
	ccount++;
}
