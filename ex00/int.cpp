/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:54:04 by abaur             #+#    #+#             */
/*   Updated: 2021/04/14 18:32:37 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversions.hpp"
#include "conversion_templates.hpp"

#include <limits>
#include <stdlib.h>

extern bool	ConvertInt(std::string str){
	unsigned	i;
	if (str[0] == '+' || str[0] == '-')
		i = 1;
	else
		i = 0;
	
	for (; i<str.size(); i++)
		if (str[i] < '0' || '9' < str[i])
			return false;

	int value = atoi(str.data());
	CastToAll<int>(value, "int");
	return true;
}
