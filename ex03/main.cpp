/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:29:43 by abaur             #+#    #+#             */
/*   Updated: 2021/03/26 18:11:37 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>
#include <sstream>
#include <stdlib.h>

static char	GetOp(std::istringstream& input){
	char c = 0;

	input >> std::skipws;
	input >> c;

	if (c == '+' || c == '-' || c == '/' || c == '*')
		return c;
	else{
		input.putback(c);
		return 0;
	}
}

static std::istringstream& operator >>(std::istringstream& src, Fixed& dst){
	float output;
	src >> output;
	dst = Fixed(output);
	return src;
}

static int	Evaluate(std::istringstream& input){
	Fixed	currentValue;
	char	nextOp;
	Fixed	nextNumber;

	input >> currentValue;
	if (input.fail()){
		std::cout << "[ERR] Bad Start of expression" << std::endl;
		return EXIT_FAILURE;
	}

	while (!input.eof())
	{
		nextOp = GetOp(input);
		if (nextOp == 0){
			if (input.eof())
				break;
			else {
				std::cout << "[ERR] Unexpected character : " << (char)input.get() << std::endl;
				return EXIT_FAILURE;
			}
		}
		input >> nextNumber;
		if (input.fail()){
			if (input.eof())
				std::cout << "[ERR] Orphan operator : " << nextOp << std::endl;
			else{
				std::string word;
				input.clear();
				input >> word;
				std::cout << "[ERR] Not a Number : " << word << std::endl;
			}
			return EXIT_FAILURE;
		}
		switch (nextOp)
		{
			default: std::cout << "[FATAL] Bad operator :" << nextOp << std::endl; return EXIT_FAILURE;
			case '+': currentValue = currentValue + nextNumber; break;
			case '-': currentValue = currentValue - nextNumber; break;
			case '*': currentValue = currentValue * nextNumber; break;
			case '/': currentValue = currentValue / nextNumber; break;
		}
	}

	std::cout << currentValue << std::endl;
	return EXIT_SUCCESS;
}

extern int	main(int argc, char** argv){
	if (argc < 2){
		std::cerr << "No expressions to evaluate." << std::endl;
		return EXIT_FAILURE;
	}
	else if (argc > 2){
		std::cerr << "Too many arguments." << std::endl;
		return EXIT_FAILURE;
	}

	std::istringstream input(argv[1]);

	return Evaluate(input);
}