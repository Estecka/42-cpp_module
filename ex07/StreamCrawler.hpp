/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StreamCrawler.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:50:15 by abaur             #+#    #+#             */
/*   Updated: 2021/03/21 19:57:09 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STREAMCRAWLER_HPP
#define STREAMCRAWLER_HPP

#include <iostream>

#define BUFFSIZEMIN	128

class StreamCrawler
{
public:
	StreamCrawler(std::istream input, std::ostream output, const char* find, const char* replace);
	~StreamCrawler();

private:
	std::istream	input;
	std::ostream	output;
	const char*	find;
	const char*	replace;

	unsigned	bufferSize;
	unsigned	findSize;
};

#endif
