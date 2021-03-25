/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:24:30 by abaur             #+#    #+#             */
/*   Updated: 2021/03/25 18:28:09 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>
#include <cmath>


const int	Fixed::fixedPoint = 8;

int	Fixed::GetFixedPoint() { return fixedPoint; } 


Fixed::Fixed(void){
	this->raw = 0;
}
Fixed::Fixed(const Fixed& original){
	*this = original;
}
Fixed::Fixed(int value){
	this->raw = value << fixedPoint;
}
Fixed::Fixed(float value){
	this->raw = (int)roundf(value * (1 << fixedPoint));
}
Fixed::~Fixed(){
}


Fixed& Fixed::operator =(const Fixed& original){
	this->raw = original.raw;
	return *this;
}
std::ostream& operator <<(std::ostream& dst, const Fixed& src){
	return dst << src.toFloat();
}


int	Fixed::toInt() const {
	return this->raw >> fixedPoint;
}
float	Fixed::toFloat() const {
	return ((float)this->raw) / (1 << fixedPoint);
}
// This functions is to precise for the subject, Alas.
std::string	Fixed::toString() const{
	std::string	result = "";
	int 	decimalPoint = fixedPoint;
	long	rawl = this->raw;

	// Creates an integer with the same digits.
	for (int i=0; i<fixedPoint; i++)
		rawl *= 10;
	rawl >>= fixedPoint;
	// Removes trailing 0 decimals
	while (decimalPoint > 0 &&  !(rawl % 10)){
		rawl /= 10;
		decimalPoint --;
	}
	// Write the fractional portion
	for (int i=0; i<decimalPoint; i++){
		char c = '0' + (rawl % 10);
		result.insert(0, &c, 1);
		rawl /= 10;
	}
	if (decimalPoint)
		result.insert(0, ".");
	// Write the integral portion
	// do-while ensures at least one digit is printed.
	do {
		char c = '0' + (rawl % 10);
		result.insert(0, &c, 1);
		rawl /= 10;
	} while (rawl);
	return result;
}
