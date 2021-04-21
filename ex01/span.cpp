/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:56:06 by abaur             #+#    #+#             */
/*   Updated: 2021/04/21 17:17:20 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

#include <algorithm>
#include <iostream>
#include <limits>
#include <stdexcept>

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

Span::Span(void) : std::vector<int>(), _dirty(false) {}
Span::Span(size_t cap) : std::vector<int>(), _dirty(false){
	this->std::vector<int>::reserve(cap);
}
Span::Span(const Span& other) : std::vector<int>(other), _dirty(other._dirty) {
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
		this->_dirty = other._dirty;
	return *this;
}

size_t	Span::size()     const { return this->std::vector<int>::size();     }
size_t	Span::capacity() const { return this->std::vector<int>::capacity(); }
std::vector<int>::const_iterator	Span::cbegin() const { return this->std::vector<int>::begin(); }
std::vector<int>::const_iterator	Span::cend()   const { return this->std::vector<int>::end();   }

void	Span::addNumber(int n) {
	if (this->size() >= this->capacity())
		throw std::length_error("Can't add any more to the Span.");
	this->push_back(n);
	this->_dirty = true;
}

unsigned int	Span::shortestSpan() {
	this->CheckSpanability();
	unsigned int shortest = std::numeric_limits<unsigned int>::max();
	for (
		std::vector<int>::const_iterator it=this->begin(), itn=it+1; 
		itn != this->end(); 
		it++, itn++
	)
	{
		shortest = min(shortest, (unsigned int)(*itn - *it));
		if (shortest == 0)
			break;
	}
	return shortest;
}
unsigned int	Span::longestSpan() {
	this->CheckSpanability();
	return (unsigned int)(this->back() - this->front());
}

void	Span::CheckSpanability() {
	if (this->size() < 2)
		throw std::logic_error("Not enough elements to span");
	if (_dirty) {
		// std::cout << "Sorting..." << std::endl;
		std::sort(this->begin(), this->end());
		_dirty = false;
	}
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
