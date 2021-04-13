/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 14:30:58 by abaur             #+#    #+#             */
/*   Updated: 2021/04/13 17:06:25 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversions.hpp"

#include <iostream>

extern void	DisplayValues(char c, int i, float f, double d){
	std::cout << "char:   " << c << std::endl;
	std::cout << "int:    " << i << std::endl;
	std::cout << "float:  " << f << std::endl;
	std::cout << "double: " << d << std::endl;
}

extern int	main(int argc, char** argv){
	for (int i=1; i<argc; i++) {
		if (i > 1)
			std::cout << "========" << std::endl;

		std::cout << "Input : " << argv[i] << std::endl;
		if (ValidateChar(argv[i]))
			ParseChar(argv[i]);
		else if (ValidateInt(argv[i]))
			ParseInt(argv[i]);
		else
			std::cout << "Unknown value type" << std::endl;
	}
}