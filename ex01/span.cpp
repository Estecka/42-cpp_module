/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:56:06 by abaur             #+#    #+#             */
/*   Updated: 2021/04/20 15:54:39 by abaur            ###   ########.fr       */
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

Span::Span(void){
	this->content  = NULL;
	this->capacity = 0;
	this->length   = 0;
}
Span::Span(size_t cap){
	this->content  = new int[cap];
	this->capacity = cap;
	this->length   = 0;
}
Span::Span(const Span& other) {
	this->capacity = 0;
	*this = other;
}
Span::~Span(){
	if (this->capacity)
		delete[] this->content;
}

Span&	Span::operator=(const Span& other) {
	this->~Span();
	this->content  = new int[other.capacity];
	this->capacity = other.capacity;
	this->length   = other.length;

	for (size_t i=0; i<length; i++)
		(*this)[i] = other[i];

	return *this;
}

size_t	Span::size() const { return this->length;   }
size_t	Span::cap()  const { return this->capacity; }

void	Span::addNumber(int n) {
	if (this->length >= this->capacity)
		throw std::length_error("Can't add any more to the Span.");
	this->content[length] = n;
	this->length++;
}

const int&	Span::operator[](size_t i) const {
	return (*(Span*)this)[i];
}
int&      	Span::operator[](size_t i) {
	if (0 <= i && i < length)
		return this->content[i];
	else
	{
		std::ostringstream	what;
		what << "Index " << i << " out of " << length << " is invalid.";
		throw std::out_of_range(what.str());
	}
}

unsigned int	Span::shortestSpan() const {
	if (this->length < 2)
		throw std::logic_error("Not enough elements to span.");
	
	unsigned int	shortest = std::numeric_limits<unsigned int>::max();
	for (size_t i=0  ; i<(this->length-1); i++)
	for (size_t j=i+1; j< this->length   ; j++)
	{
		shortest = min(shortest, span(content[i], content[j]));
		if (shortest == 0)
			return shortest;
	}
	return shortest;
}
unsigned int	Span::longestSpan() const {
	if (this->length < 2)
		throw std::logic_error("Not enough elements to span.");

	int	smallest = std::numeric_limits<int>::max();
	int	highest  = std::numeric_limits<int>::min();

	for (size_t i=0; i<length; i++){
		if (smallest > content[i])
			smallest = content[i];
		if (highest < content[i])
			highest = content[i];
	}
	return span(smallest, highest);
}

void	Span::Dump() const {
	std::cout \
		<< this->content << "[" << this->length << "/" << this->capacity << "]{";
	for (size_t i=0; i<this->length; i++) {
		std::cout << this->content[i];
		if (i+1 != length)
			std::cout << ", ";
	}
	std::cout << " }" << std::endl;
}
