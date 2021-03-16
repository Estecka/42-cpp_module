/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact_search.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:15:58 by abaur             #+#    #+#             */
/*   Updated: 2021/03/16 21:35:48 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

#include <stdlib.h>

static bool	IsNumber(std::string s)
{
	for (unsigned int i=0; i<s.length(); i++)
		if (s[i] < '0' || '9' < s[i])
			return false;
	return true;
}

void	contact::Search() {
	std::string	input;
	signed int 	index;

	if (ccount <= 0) {
		std::cout << "I searched far and wide, but found naught but the sand un\
der my feet." << std::endl;
		return;
	}

	std::cout << "Please select a test subject : " << std::endl \
		<< "     index | First Name |  Last Name |   Nickname |" << std::endl \
		<< "----------:|-----------:|-----------:|-----------:|" << std::endl \
		;
	for (unsigned i=0; i<ccount; i++)
		clist[i].DisplayRow(i);

	getline(std::cin, input);
	if (!IsNumber(input)) {
		std::cout << "You're not making any sense." << std::endl;
		return ;
	}
	index = atoi(input.c_str());
	if (index < 0 || ccount <= (unsigned)index) {
		std::cout << "I'm afraid this is outside of the realm of possibilities"\
			<< std::endl;
		return;
	} 
	else {
		std::cout << "You have chosen subject n°" << index \
			<< ", this is an excellent choice." << std::endl;
		clist[index].DisplayFull();
	}
}

static std::string	AlignString(std::string s) {
	std::string	rvalue;

	if (s.length() <= 10)
	{
		rvalue = "";
		for (unsigned i=0; i<(10-s.length()); i++)
			rvalue += " ";
		rvalue += s;
	}
	else
	{
		rvalue = s.substr(0, 9);
		rvalue += ".";
	}
	return rvalue;
}

void	contact::DisplayRow(unsigned i) {
	std::cout \
		<< "         " << i << " | " \
		<< AlignString(this->firstName) << " | " \
		<< AlignString(this->lastName ) << " | " \
		<< AlignString(this->nickName ) << " | " \
		<< std::endl;
}

void	contact::DisplayFull(){
}
