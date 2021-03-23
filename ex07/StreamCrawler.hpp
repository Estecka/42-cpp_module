/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StreamCrawler.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:50:15 by abaur             #+#    #+#             */
/*   Updated: 2021/03/23 19:00:35 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STREAMCRAWLER_HPP
#define STREAMCRAWLER_HPP

#include <fstream>

#define BUFFSIZEMIN	128

#pragma clang diagnostic ignored "-Wunused-private-field"

class StreamCrawler
{
public:
	StreamCrawler(std::ifstream& input, std::ofstream& output, const char* find, const char* replace);
	~StreamCrawler();

	bool	ReplaceAll();

private:
	std::ifstream&	input;
	std::ofstream&	output;
	char*	buffer;
	const char*	find;
	const char*	replace;

	size_t	bufferSize;
	size_t	bufferCap;
	size_t	flushCap;
	size_t	findSize;
	size_t	cursor;

	/*
	* Finds the first occurrence of `find` in the buffer.
	* `cursor` should only be called when `cursor` is 0.
	* @return	The index of the first character found, or `bufferSize` if no 
	* needle were found.
	*/
	size_t	FindNextNeedle();

	/*
	* Reads some characters from the input, and appends them to the buffers.
	* This will discard as many characters from the beginning of the buffer
	*/
	bool	Refill();

	/*
	* Flushes some characters from the buffer into the output.
	* @param size_t count	The amount of characters to flush
	* @return bool
	* 	TRUE 	Ok;
	* 	FALSE	Error;
	*/
	bool	Flush(size_t count);

	/*
	* Discards some characters from the buffer, and write `replace` into the 
	* output.
	* @param size_t count	The amount of characters to discard.
	* @return bool
	* 	TRUE 	Ok;
	* 	FALSE	Error;
	*/
	bool	Replace(size_t index);
};

#endif
