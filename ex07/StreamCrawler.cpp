/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StreamCrawler.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:58:20 by abaur             #+#    #+#             */
/*   Updated: 2021/03/23 20:02:54 by abaur            ###   ########.fr       */
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
	if(!this->Refill())
		return false;

	while (this->bufferSize != 0)
	{
		size_t	needle = this->FindNextNeedle();
		bool	ok = true;

		if (needle)
			ok &= this->Flush(needle);
		this->cursor = needle;
		if (needle < bufferSize)
			ok &= this->ReplaceOnce();
		ok &= this->Refill();
		if (!ok)
			return false;
		break;
	}
	return true;
}

bool	StreamCrawler::Refill(){
	size_t	rcount;

	if (bufferSize && cursor)
		memmove(&buffer[0], &buffer[cursor], bufferSize);
	this->cursor = 0;
	rcount = bufferCap - bufferSize;
	input.read(&buffer[bufferSize], rcount);
	bufferSize += input.gcount();

	if (input.fail())
		std::cout << "[ERR] Failed to read from input" << std::endl;
	return !input.fail();
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
	return bufferSize;
}

bool	StreamCrawler::Flush(size_t count){
	if (count > flushCap){
		std::cout << "[WARN] Attempted to flush more than the flush cap: " 
			<< count << " lowered to " << flushCap << std::endl;
		count = bufferSize;
	}
	if (count > bufferSize) {
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
