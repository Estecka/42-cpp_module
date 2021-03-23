/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:09:41 by abaur             #+#    #+#             */
/*   Updated: 2021/03/23 21:57:33 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StreamCrawler.hpp"

#include <iostream>
#include <fstream>

#include <stdlib.h>

/*
* @param const char* name	The original name of the file to read.
* @param ifstream input	Returns the opened input file.
* @param ofstream output	Returns the opened output file.
* @return bool
*	TRUE 	ok; 
*	FALSE	A file couldn't be opened;
*/
static bool	OpenStreams(const char* inputName, std::ifstream* input, std::ofstream* output){
	std::string	outputName = inputName + (std::string)".replace";

	input->open(inputName, std::ios::in);
	if (input->fail()){
		std::cout << "[ERR] Failed to open input file." << std::endl;
		return false;
	}

	output->open(outputName.data(), std::ios::out);
	if (output->fail()){
		std::cout << "[ERR] Failed to open output file." << std::endl;
		input->close();
		return false;
	}

	return true;
}

extern int	main(int argc, char** argv){
	std::ifstream	input;
	std::ofstream	output;

	if (argc != 4){
		if (argc < 4)
			std::cout << "Not enough arguments" << std::endl;
		else if (argc > 4)
			std::cout << "Too many arguments" << std::endl;
		return EXIT_FAILURE;
	}
	if (argv[2][0] == '\0'){
		std::cout << "Empty needle" << std::endl;
		return EXIT_FAILURE;
	}

	if (!OpenStreams(argv[1], &input, &output))
		return EXIT_FAILURE;

	StreamCrawler crawler = StreamCrawler(input, output, argv[2], argv[3]);
	bool status = crawler.ReplaceAll();
	input.close();
	output.close();
	return status ? EXIT_SUCCESS : EXIT_FAILURE;
}
