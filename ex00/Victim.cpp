/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:53:22 by abaur             #+#    #+#             */
/*   Updated: 2021/03/31 19:21:55 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim(void){
	this->name = "nondescript victim";
}
Victim::Victim(const std::string& name){
	this->name = name;
	std::cout << "Some random victim called " << this->name << " just appeard!"\
		<< std::endl;
}
Victim::Victim(const Victim& original){
	*this = original;
	std::cout << "Some random victim called " << this->name << " just appeard!"\
		<< std::endl;
}
Victim::~Victim(){
	std::cout << "Victim " << this->name << " just died for no apparent reason!"\
		<< std::endl;
}

Victim&	Victim::operator =(const Victim& other){
	this->name = other.name;
}

std::ostream&	operator <<(std::ostream& dst, const Victim& src){
	dst << "I am " << src.getName() << " and I like otters!" << std::endl;
}

std::string	Victim::getName() const  { return this->name; }

void	Victim::getPolymorphed() const {
	std::cout << this->name << " has been turned into a cute little sheep!"\
		<< std::endl;
}

