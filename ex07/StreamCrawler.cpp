/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StreamCrawler.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:58:20 by abaur             #+#    #+#             */
/*   Updated: 2021/03/23 21:44:05 by abaur            ###   ########.fr       */
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
	this->findSize = strlen(find);
	this->replace = replace;
	this->replaceSize = strlen(replace);

	this->bufferCap = (findSize * 2) - 1;
	if (findSize < BUFFSIZEMIN)
		this->bufferCap = BUFFSIZEMIN;
	this->flushCap = bufferCap - findSize + 1;

	this->buffer = new char[bufferCap];
	this->bufferSize = 0;
	this->cursor = bufferCap;

	// std::cout \
	// 	<< "[DEBUG] Needle size: " << findSize  << std::endl \
	// 	<< "[DEBUG] bufferCap: "   << bufferCap << std::endl \
	// 	<< "[DEBUG] flushCap: "    << flushCap  << std::endl \
	// 	;
}
StreamCrawler::~StreamCrawler(){
	delete[] buffer;
}


bool	StreamCrawler::ReplaceAll()
{
	while (!input.eof())
	{
		size_t	needle;
		size_t	flushAmount;

		if (!this->Refill())
			return false;
		needle = this->FindNextNeedle();

		if (needle != (size_t)-1)
			flushAmount = needle;
		else if (input.eof())
			flushAmount = bufferSize;
		else
			flushAmount = flushCap;

		if (flushAmount && !this->Flush(flushAmount))
			return false;
		if ((needle != (size_t)-1) && !this->ReplaceOnce())
			return false;
	}
	return true;
}

// #include <stdio.h>
bool	StreamCrawler::Refill(){
	size_t	rcount;

	if (bufferSize && cursor)
		memmove(&buffer[0], &buffer[cursor], bufferSize);
	rcount = bufferCap - bufferSize;
	input.read(&buffer[bufferSize], rcount);

	if (input.fail() && !input.eof()){
		std::cout << "[ERR] Failed to read from input" << std::endl \
			<< "[DEBUG] failbit: "    << input.failbit << " " << strerror(input.failbit) << std::endl \
			<< "[DEBUG] badbit:  "    << input.badbit  << " " << strerror(input.badbit) << std::endl \
			<< "[DEBUG] cursor: "     << cursor         << std::endl \
			<< "[DEBUG] bufferSize: " << bufferSize     << std::endl \
			<< "[DEBUG] rcount:"      << rcount         << std::endl \
			<< "[DEBUG] gcount(): "   << input.gcount() << std::endl \
			;
		// printf("[DEBUG] Buffer:\n%.*s\n", (int)bufferSize, buffer);
		// printf("[DEBUG] Read:\n%.*s\n", (int)input.gcount(), buffer+bufferSize);
	}

	this->cursor = 0;
	bufferSize += input.gcount();
	return (!input.fail() || input.eof());
}

/*
* The null-terminator at the end of `needle` is not compared against `candidate`.
* Eventual `\0`'s in candidate are still compared against `needle`.
*/
static bool	miinstrcmp(const char* needle, const char* candidate){
	while (*needle){
		if (*needle != *candidate)
			return false;
		needle++;
		candidate++;
	}
	return true;
}

size_t	StreamCrawler::FindNextNeedle(){
	for (size_t i=0; findSize<=(bufferSize-i); i++){
		if (miinstrcmp(find, buffer+i))
			return (i);
	}
	return -1;
}

bool	StreamCrawler::Flush(size_t count){
	if (!input.eof() && count > flushCap){
		std::cout << "[WARN] Attempted to flush more than the flush cap: " 
			<< count << " lowered to " << flushCap << std::endl;
		count = bufferSize;
	} else if (count > bufferSize) {
		std::cout << "[WARN] Attempted to flush more than available: " 
			<< count << " lowered to " << bufferSize << std::endl;
		count = bufferSize;
	}

	this->output.write(buffer, count);
	this->cursor = count;
	this->bufferSize -= count;

	if (output.fail())
		std::cout << "[ERR] Flush operation failed" << std::endl;
	return !output.fail();
}

bool	StreamCrawler::ReplaceOnce(){
	if (bufferSize < findSize){
		std::cout << "[ERR] Invalid Replace operation" << std::endl;
		return false;
	}

	this->output.write(replace, replaceSize);
	this->cursor += findSize;
	this->bufferSize -= findSize;

	if (output.fail())
		std::cout << "[ERR] Replace operation failed" << std::endl;
	return !output.fail();
}
