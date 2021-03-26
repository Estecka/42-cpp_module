/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:29:43 by abaur             #+#    #+#             */
/*   Updated: 2021/03/26 23:57:56 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>
#include <sstream>
#include <stdlib.h>

static char	GetOp(std::istream& input){
	char c = 0;

	input >> std::skipws;
	input >> c;

	if (c == '+' || c == '-' || c == '/' || c == '*')
		return c;
	else if (input.eof())
		return -1;
	else {
		input.putback(c);
		return 0;
	}
}

static std::istream& operator >>(std::istream& src, Fixed& dst){
	float output;
	src >> output;
	dst = Fixed(output);
	return src;
}

static int	ErrNaN(std::istream& input){
	std::string word;

	input.clear();
	input >> word;
	std::cout << "[ERR] Not a Number : " << word << std::endl;

	return EXIT_FAILURE;
}

static int	Evaluate(std::istream& input){
	Fixed	currentValue;
	char	nextOp;
	Fixed	nextNumber;

	input >> currentValue;
	if (input.fail())
		return ErrNaN(input);

	while (!input.eof())
	{
		nextOp = GetOp(input);
		if (nextOp == -1)
			break;
		else if (nextOp == 0){
			std::cout << "[ERR] Not an operator : " << (char)input.get() << std::endl;
			return EXIT_FAILURE;
		}
		input >> nextNumber;
		if (input.fail()){
			if (input.eof())
				std::cout << "[ERR] Orphan operator : " << nextOp << std::endl;
			else
				ErrNaN(input);
			return EXIT_FAILURE;
		}
		switch (nextOp)
		{
			default: std::cout << "[FATAL] Bad operator :" << nextOp << std::endl; return EXIT_FAILURE;
			case '+': currentValue = currentValue + nextNumber; break;
			case '-': currentValue = currentValue - nextNumber; break;
			case '*': currentValue = currentValue * nextNumber; break;
			case '/': 
				if (nextNumber != 0)
					currentValue = currentValue / nextNumber;
				else {
					std::cout << "[ERR] Division by 0" << std::endl;
					return EXIT_FAILURE;
				}
				break;
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