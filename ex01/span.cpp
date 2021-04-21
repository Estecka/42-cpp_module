/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:56:06 by abaur             #+#    #+#             */
/*   Updated: 2021/04/21 16:25:49 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

#include <iostream>
#include <limits>
#include <stdexcept>
#include <sstream>

unsigned int	max(unsigned int a, unsigned int b){
	if (a > b)
		return a;
	else
		return b;
}
unsigned int	min(unsigned int a, unsigned int b){
	if (a < b)
		return a;
	else
		return b;
}

unsigned int	span(int a, int b){
	if (a < b)
		return b - a;
	else
		return a - b;
}

Span::Span(void) : std::vector<int>(){
	this->_length   = 0;
}
Span::Span(size_t cap) : std::vector<int>(cap){
	this->_length   = 0;
}
Span::Span(const Span& other) : std::vector<int>(other) {
	this->_length = other._length;
}
Span::~Span(){
}

Span&	Span::operator=(const Span& other) {
	this->std::vector<int>::operator=(other);
	this->_length   = other._length;
	return *this;
}

void	Span::addNumber(int n) {
	if (this->_length >= this->capacity())
		throw std::length_error("Can't add any more to the Span.");
	(*this)[_length] = n;
	this->_length++;
}

unsigned int	Span::shortestSpan() const {
	return 0;
}
unsigned int	Span::longestSpan() const {
	return 0;
}

void	Span::Dump() const {
	std::cout \
		<< "[" << this->_length << "/" << this->capacity() << "]{";
	for (size_t i=0; i<this->_length; i++) {
		std::cout << (int)(*this)[i];
		if (i+1 != _length)
			std::cout << ", ";
	}
	std::cout << " }" << std::endl;
}
