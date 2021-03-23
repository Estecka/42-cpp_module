/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StreamCrawler.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:50:15 by abaur             #+#    #+#             */
/*   Updated: 2021/03/23 15:51:52 by abaur            ###   ########.fr       */
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
	const char*	find;
	const char*	replace;

	unsigned	bufferSize;
	unsigned	findSize;
};

#endif
