/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact_search.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:15:58 by abaur             #+#    #+#             */
/*   Updated: 2021/03/16 19:11:49 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

void	contact::Search()
{
	if (ccount <= 0)
	{
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
}

static std::string	AlignString(std::string s)
{
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

void	contact::DisplayRow(unsigned i)
{
	std::cout \
		<< "         " << i << " | " \
		<< AlignString(this->firstName) << " | " \
		<< AlignString(this->lastName ) << " | " \
		<< AlignString(this->nickName ) << " | " \
		<< std::endl;
}
