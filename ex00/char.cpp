/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:14:16 by abaur             #+#    #+#             */
/*   Updated: 2021/04/13 18:10:07 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversions.hpp"
#include "conversion_templates.hpp"

#include <iostream>
#include <string.h>

extern bool	ConvertChar(std::string str) {
	char	c;

	if (str.size() == 4)
	{
		if (str != "'\\\\'" && str != "'\\''")
			return false;
		else
			c = str[2];
	}
	else if (str.size() != 3)
		return false;
	else if (str[0] != '\'' && str[2] != '\'')
		return false;
	else if (str[1] == '\\' || str[1] == '\'')
		return false;
	else
		c = str[1];

	CastToAll<char>(c);
	return true;
}
