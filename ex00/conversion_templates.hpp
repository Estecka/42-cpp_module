/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_templates.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:51:00 by abaur             #+#    #+#             */
/*   Updated: 2021/04/13 19:13:44 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_TEMPLATES_HPP
#define CONVERSION_TEMPLATES_HPP

#include "math.h"
#include <exception>
#include <iostream>
#include <limits>
#include <sstream>
#include <typeinfo>

template <typename T> T	CastLiteral(std::string literal){
	std::istringstream stream(literal);
	T	value;

	stream >> value;
	if (stream.fail() || !stream.eof())
		throw std::invalid_argument(std::string("Could not convert ") + literal);
	return (value);
}


template <typename T> void	CastToChar(T value){
	std::cout << "char:   ";

	if (isnan(value) || value < std::numeric_limits<char>::min() || std::numeric_limits<char>::max() < value)
		std::cout << "impossible";
	else if (!isprint(value))
		std::cout << "non displayable";
	else
		std::cout << static_cast<int>(value);
	std::cout << std::endl;
}

template <typename T> void	CastToInt(T value){
	std::cout << "int:    ";
	if(isnan(value) || value < std::numeric_limits<int>::min() || std::numeric_limits<int>::max() < value)
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(value);
	std::cout << std::endl;
}

template <typename T> void	CastToFloat(T value){
	std::cout << "float:  " << static_cast<float>(value) << 'f' << std::endl;
}

template <typename T> void	CastToDouble(T value){
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}


template <typename T> void	CastToAll(T value){
	std::cout << "This is a ";
	switch (typeid(T).name()[0])
	{
		default:  std::cout << "???";    break;
		case 'c': std::cout << "char";   break;
		case 'i': std::cout << "int";    break;
		case 'f': std::cout << "float";  break;
		case 'd': std::cout << "double"; break;
	}
	std::cout << std::endl;
	CastToChar<T>(value);
	CastToInt<T>(value);
	CastToFloat<T>(value);
	CastToDouble<T>(value);
}

#endif
