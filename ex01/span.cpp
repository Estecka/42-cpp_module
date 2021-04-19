/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:56:06 by abaur             #+#    #+#             */
/*   Updated: 2021/04/19 18:40:40 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

#include <stdexcept>
#include <sstream>
#include <limits>

int	max(int a, int b){
	if (a > b)
		return a;
	else
		return b;
}
int	min(int a, int b){
	if (a < b)
		return a;
	else
		return b;
}

int	span(int a, int b){
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
	this[length] = n;
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

int	Span::shortestSpan() const {
	if (this->length < 2)
		throw std::logic_error("Not enough elements to span.");
	
	int	shortest = std::numeric_limits<int>::max();
	for (size_t i=0; (i+1)<this->length; i++)
		shortest = min(shortest, span(content[i], content[i+1]));
	return shortest;
}
int	Span::longestSpan() const {
	if (this->length < 2)
		throw std::logic_error("Not enough elements to span.");
	
	int	longest = std::numeric_limits<int>::max();
	for (size_t i=0; (i+1)<this->length; i++)
		longest = max(longest, span(content[i], content[i+1]));
	return longest;
}
