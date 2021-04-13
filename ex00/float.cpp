/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 17:15:17 by abaur             #+#    #+#             */
/*   Updated: 2021/04/13 17:44:01 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversions.hpp"

bool	ValidateFloat(std::string str){
	return ValidateDouble(str.substr(0, str.size()-1)) 
		&& str[str.size()-1] == 'f';
}
bool	ValidateDouble(std::string str){
	bool	floatingPoint;

	for (unsigned i=0; i<str.size(); i++)
	{
		if (str[i] == '.')
		{
			if (floatingPoint)
				return false;
			else
				floatingPoint = true;
		}
		else if (str[i] < '0' || '9' < str[i])
			return false;
	}
	return true;
}

void	ParseFloat(std::string str){
	float	f;

	f = CastLiteral<float>(str);
	CastToAll<float>(f);
}

void	ParseDouble(std::string str){
	double	f;

	f = CastLiteral<double>(str);
	CastToAll<double>(f);
}
