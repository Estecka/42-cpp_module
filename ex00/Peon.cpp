/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:27:31 by abaur             #+#    #+#             */
/*   Updated: 2021/03/31 19:31:55 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

Peon::Peon(void) : Victim() {
	this->name = "Jeremiah the default Peon";
}
Peon::Peon(const std::string& name) : Victim(name) {
	std::cout << "Zog zog." << std::endl;
}
Peon::Peon(const Peon& original){
	*this = original;
	std::cout << "Zog zog." << std::endl;
}
Peon::~Peon(){
	std::cout << "Bleuark..." << std::endl;
}

Peon&	Peon::operator =(const Peon& other){
	this->name = other.name;
}

void	Peon::getPolymorphed() const {
	std::cout << this->name << " has been turned into a pink pony!"\
		<< std::endl;
}

