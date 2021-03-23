/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StreamCrawler.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:58:20 by abaur             #+#    #+#             */
/*   Updated: 2021/03/23 15:50:46 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StreamCrawler.hpp"

StreamCrawler::StreamCrawler
(std::ifstream& input, std::ofstream& output, const char* find, const char* replace)
: input(input), output(output)
{
	this->find = find;
	this->replace = replace;
}
StreamCrawler::~StreamCrawler(){}


bool	StreamCrawler::ReplaceAll()
{
	return true;
}
