/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_templates.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:51:00 by abaur             #+#    #+#             */
/*   Updated: 2021/04/13 17:42:08 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_TEMPLATES_HPP
#define CONVERSION_TEMPLATES_HPP

#include <exception>
#include <iostream>
#include <sstream>

template <typename SRC, typename DST> bool	IsCastable(SRC value) {
	return (value == (SRC)(DST)value);
}

template <typename T> T	CastLiteral(std::string literal){
	std::istringstream stream(literal);
	T	value;

	stream >> value;
	if (stream.fail())
		throw std::invalid_argument(std::string("Could not convert ") + literal);
	return (value);
}

template <typename T> void	CastToChar(T value){
	std::cout << "char:   " << (char)value << std::endl;
}
template <typename T> void	CastToInt(T value){
	std::cout << "int:    " << (int)value << std::endl;
}
template <typename T> void	CastToFloat(T value){
	std::cout << "float:  " << (float)value << std::endl;
}
template <typename T> void	CastToDouble(T value){
	std::cout << "double: " << (double)value << std::endl;
}

template <typename T> void	CastToAll(T value){
	CastToChar<T>(value);
	CastToInt<T>(value);
	CastToFloat<T>(value);
	CastToDouble<T>(value);
}

#endif
