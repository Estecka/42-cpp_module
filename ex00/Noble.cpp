/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Noble.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:46:24 by abaur             #+#    #+#             */
/*   Updated: 2021/04/01 15:58:48 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Noble.hpp"

Noble::Noble(void) : Victim() {
	this->name = "Norbert";
	this->title = "the Default Noble";
}
Noble::Noble(const std::string& name, const std::string& title) : Victim(name) {
	this->name = name;
	this->title = title;
}
Noble::Noble(const Noble& other){
	*this = other;
}
Noble::~Noble(){
}

Noble& Noble::operator =(const Noble& other){
	this->name = other.name;
	this->title = other.title;
	return *this;
}

std::string	Noble::getTitle() const { return this->title; }

void	Noble::getPolymorphed() const {
	std::cout << this->name << ", " << this->title \
		<< ", has been turned into a Platypus !"\
		<< std::endl;
}
