/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:25:21 by abaur             #+#    #+#             */
/*   Updated: 2021/03/31 19:35:12 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include <exception>

Sorcerer::Sorcerer(void){
	std::cerr << "A nameless Sorcerer was about to be born. "
		<< "Such a crime against the concept of sorcery itself tears the fabric "\
		<< "of space-time, and so the world ends."
		<< std::endl;
	throw std::exception();
}
Sorcerer::Sorcerer(const std::string& name, const std::string& title){
	this->name = name;
	this->title = title;
	std::cout << name << ", " << title << ", is born!" << std::endl;
}
Sorcerer::Sorcerer(const Sorcerer& original){
	*this = original;
	std::cout << name << ", " << title << ", is born!" << std::endl;
}
Sorcerer::~Sorcerer(){
	std::cout << name << ", " << title << ", is dead. "\
		<< "Consequences will never be the same!"\
		<< std::endl;
}

Sorcerer&	Sorcerer::operator =(const Sorcerer& other){
	this->name = other.name;
	this->title = other.title;
	return *this;
}

std::ostream&	operator <<(std::ostream& dst, const Sorcerer& src){
	dst << "I am " << src.getName() << ", " << src.getTitle() \
		<< ", and I like ponies!" << std::endl;
	return dst;
}

std::string	Sorcerer::getName() const  { return this->name;  }
std::string	Sorcerer::getTitle() const { return this->title; }

void	Sorcerer::polymorph(const Victim& victim) const {
	victim.getPolymorphed();
}
