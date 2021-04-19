/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:56:06 by abaur             #+#    #+#             */
/*   Updated: 2021/04/19 18:56:58 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

#include <stdexcept>
#include <sstream>
#include <limits>

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

size_t	Span::size()     const { return this->length; }

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
	for (size_t i=0; (i+1)<this->length; i++)
		shortest = min(shortest, span(content[i], content[i+1]));
	return shortest;
}
unsigned int	Span::longestSpan() const {
	if (this->length < 2)
		throw std::logic_error("Not enough elements to span.");
	
	unsigned int	longest = 0;
	for (size_t i=0; (i+1)<this->length; i++)
		longest = max(longest, span(content[i], content[i+1]));
	return longest;
}
