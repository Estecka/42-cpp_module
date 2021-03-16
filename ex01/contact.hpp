/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 23:04:07 by abaur             #+#    #+#             */
/*   Updated: 2021/03/16 16:51:42 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class contact
{
public:
	static contact	clist[8];
	static unsigned	ccount;

	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	login;

	std::string	postalAdress;
	std::string	emailAdress;
	std::string	phoneNumber;

	std::string	birthdayDate;
	std::string	favoriteMeal;
	std::string	underwearColor;
	std::string	darkestSecret;

	contact();
	~contact();

	static void	add();
};

#endif
