/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:56:06 by abaur             #+#    #+#             */
/*   Updated: 2021/04/21 16:42:41 by abaur            ###   ########.fr       */
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

Span::Span(void) : std::vector<int>(){}
Span::Span(size_t cap) : std::vector<int>(){
	this->std::vector<int>::reserve(cap);
}
Span::Span(const Span& other) : std::vector<int>(other) {
	this->std::vector<int>::reserve(other.capacity());
	if (this->capacity() != other.capacity())
		throw std::length_error("Initialization failed with wrong size.");
}
Span::~Span(){
}

Span&	Span::operator=(const Span& other) {
	this->std::vector<int>::operator=(other);
	this->std::vector<int>::reserve(other.capacity());
	if (this->capacity() != other.capacity())
		throw std::length_error("Assignation failed with wrong size.");
	return *this;
}

size_t	Span::size()     const { return this->std::vector<int>::size();     }
size_t	Span::capacity() const { return this->std::vector<int>::capacity(); }

void	Span::addNumber(int n) {
	if (this->size() >= this->capacity())
		throw std::length_error("Can't add any more to the Span.");
	this->push_back(n);
}

unsigned int	Span::shortestSpan() const {
	return 0;
}
unsigned int	Span::longestSpan() const {
	return 0;
}

void	Span::Dump() const {
	std::cout \
		<< "[" << this->size() << "/" << this->capacity() << "]{";
	for (size_t i=0; i<size(); i++) {
		std::cout << (*this)[i];
		if (i+1 != size())
			std::cout << ", ";
	}
	std::cout << " }" << std::endl;
}
