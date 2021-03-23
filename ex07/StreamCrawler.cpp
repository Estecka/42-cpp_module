/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StreamCrawler.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:58:20 by abaur             #+#    #+#             */
/*   Updated: 2021/03/23 16:48:55 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StreamCrawler.hpp"

#include <iostream>

#include <string.h>

StreamCrawler::StreamCrawler
(std::ifstream& input, std::ofstream& output, const char* find, const char* replace)
: input(input), output(output)
{
	this->find = find;
	this->replace = replace;

	this->findSize = strlen(find);
	this->bufferCap = (findSize * 2) - 1;
	if (findSize < BUFFSIZEMIN)
		this->bufferCap = BUFFSIZEMIN;
	this->flushCap = bufferCap - findSize + 1;

	this->buffer = new char[bufferCap];
	this->bufferSize = 0;
	this->cursor = 0;

	std::cout \
		<< "Needle size: " << findSize  << std::endl \
		<< "bufferCap: "   << bufferCap << std::endl \
		<< "flushCap: "    << flushCap  << std::endl \
		;
}
StreamCrawler::~StreamCrawler(){
	delete[] buffer;
}


bool	StreamCrawler::ReplaceAll()
{
	return true;
}
