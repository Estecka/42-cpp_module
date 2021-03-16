/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 23:04:07 by abaur             #+#    #+#             */
/*   Updated: 2021/03/16 14:12:23 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class contact
{
public:
	char*	firstName;
	char*	lastName;
	char*	nickName;
	char*	login;

	char*	postalAdress;
	char*	emailAdress;
	char*	phoneNumber;

	char*	birthdayDate;
	char*	favoriteMeal;
	char*	darkestSecret;

	contact();
	~contact();
};

contact::contact()
{
}

contact::~contact()
{
}
