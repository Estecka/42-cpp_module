/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 17:15:17 by abaur             #+#    #+#             */
/*   Updated: 2021/04/13 18:25:59 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversions.hpp"

#include <limits>

bool	ConvertDouble(std::string str){
	double	value;

	if (str == "nan")
		value = std::numeric_limits<double>::quiet_NaN();
	else if (str == "+inf")
		value = std::numeric_limits<double>::infinity();
	else if (str == "-inf")
		value = -std::numeric_limits<double>::infinity();
	else try { 
		value = CastLiteral<double>(str); 
	} catch (const std::invalid_argument& e){
		return false;
	}
	
	CastToAll<double>(value);
	return true;
}


bool	ConvertFloat(std::string str){
	float value;

	if (str[str.size() - 1] != 'f')
		return false;
	str = str.substr(0, str.size() - 1);


	if (str == "nan")
		value = std::numeric_limits<float>::quiet_NaN();
	else if (str == "+inf")
		value = std::numeric_limits<float>::infinity();
	else if (str == "-inf")
		value = -std::numeric_limits<float>::infinity();
	else try { 
		value = CastLiteral<float>(str); 
	} catch (const std::invalid_argument& e){
		return false;
	}
	
	CastToAll<float>(value);
	return true;
}
