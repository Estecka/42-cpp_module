/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:14:16 by abaur             #+#    #+#             */
/*   Updated: 2021/04/13 15:51:40 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversions.hpp"

#include <iostream>
#include <string.h>

bool	ValidateChar(std::string str) {
	if (str.size() == 4)
	{
		if (str != "'\\\\'" && str != "'\\''")
			return false;
		else
			return true;
	}
	else if (str.size() != 3)
		return false;
	else if (str[0] != '\'' && str[2] != '\'')
		return false;
	else if (str[1] == '\\' || str[1] == '\'')
		return false;
	else
		return true;
}

void	ParseChar(std::string str) {
	char	c;

	if (str[1] == '\\')
		c = str[2];
	else
		c = str[1];

	DisplayValues(
		c,
		static_cast<int>(c),
		static_cast<float>(c),
		static_cast<double>(c)
	);
}
