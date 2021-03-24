/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:24:30 by abaur             #+#    #+#             */
/*   Updated: 2021/03/24 19:46:53 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>


const int	Fixed::fixedPoint = 8;

int	Fixed::GetFixedPoint() { return fixedPoint; } 


Fixed::Fixed(void){
	std::cout << "Default constructor called" << std::endl;
	this->raw = 0;
}
Fixed::Fixed(const Fixed& original){
	std::cout << "Copy constructor called" << std::endl;
	*this = original;
}
Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator =(const Fixed& original){
	std::cout << "Assignation operator called" << std::endl;
	this->raw = original.getRawBits();
	return *this;
}


int 	Fixed::getRawBits() const { 
	std::cout << "getRawBits member function called" << std::endl;
	return this->raw; 
}
void	Fixed::setRawBits(int raw){
	std::cout << "setRawBits member function called" << std::endl;
	this->raw = raw;
}
