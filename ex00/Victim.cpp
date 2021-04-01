/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:53:22 by abaur             #+#    #+#             */
/*   Updated: 2021/04/01 15:49:49 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim(void){
	this->name = "nondescript victim";
	std::cout << "Some random victim called " << this->name << " just appeared!"\
		<< std::endl;
}
Victim::Victim(const std::string& name){
	this->name = name;
	std::cout << "Some random victim called " << this->name << " just appeared!"\
		<< std::endl;
}
Victim::Victim(const Victim& original){
	*this = original;
	std::cout << "Some random victim called " << this->name << " just appeared!"\
		<< std::endl;
}
Victim::~Victim(){
	std::cout << "Victim " << this->name << " just died for no apparent reason!"\
		<< std::endl;
}

Victim&	Victim::operator =(const Victim& other){
	this->name = other.name;
	return *this;
}

std::ostream&	operator <<(std::ostream& dst, const Victim& src){
	dst << "I'm " << src.getName() << " and I like otters!" << std::endl;
	return dst;
}

std::string	Victim::getName() const  { return this->name; }

void	Victim::getPolymorphed() const {
	std::cout << this->name << " has been turned into a cute little sheep!"\
		<< std::endl;
}

