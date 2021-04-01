/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Noble.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:46:24 by abaur             #+#    #+#             */
/*   Updated: 2021/04/01 16:18:01 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Noble.hpp"

Noble::Noble(void) : Victim() {
	this->name = "Norbert";
	this->title = "the Default Noble";
	std::cout << "* A fanfare sound can be heard in the distance * " << std::endl;
}
Noble::Noble(const std::string& name, const std::string& title) : Victim(name) {
	this->name = name;
	this->title = title;
	std::cout << "* A fanfare sound can be heard in the distance * " << std::endl;
}
Noble::Noble(const Noble& other) : Victim(other) {
	*this = other;
	std::cout << "* A fanfare sound can be heard in the distance * " << std::endl;
}
Noble::~Noble(){
	std::cout << "Sacrébleu !" << std::endl;
}

Noble& Noble::operator =(const Noble& other){
	this->name = other.name;
	this->title = other.title;
	return *this;
}

std::string	Noble::getTitle() const { return this->title; }

std::ostream& Noble::ToStream(std::ostream& dst) const {
	dst << "I am " << this->name << ", " << this->title \
		<< ", and I have come to seize this land !"\
		<< std::endl;
	return dst;
}

void	Noble::getPolymorphed() const {
	std::cout << this->name << ", " << this->title \
		<< ", has been turned into a Platypus !"\
		<< std::endl;
}
