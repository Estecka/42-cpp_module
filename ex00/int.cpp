/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:54:04 by abaur             #+#    #+#             */
/*   Updated: 2021/04/13 17:01:09 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversions.hpp"

#include <limits>
#include <stdlib.h>

bool	ValidateInt(std::string str){
	unsigned	i;
	if (str[0] == '+' || str[0] == '-')
		i = 1;
	else
		i = 0;
	
	for (; i<str.size(); i++)
		if (str[i] < '0' || '9' < str[i])
			return false;

	return true;
}

void	ParseInt(std::string str) {
	int	i;

	i = atoi(str.data());
	CastToAll<int>(i);
}
