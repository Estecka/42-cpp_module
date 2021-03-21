/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 17:07:39 by abaur             #+#    #+#             */
/*   Updated: 2021/03/21 18:25:54 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

#include <time.h>

Human::Human(void) : brain((long)this & 1) {
	// this->brain = Brain((long)this & 1);
	this->time_to_die = 410;
	this->status = "sleeping";
}
Human::~Human(){
	// std::cout << time(NULL) << " " << this->identify() << " died." << std::endl;
}


const Brain&	Human::getBrain(){ return this->brain; }
std::string	Human::identify(){ return this->brain.identify(); }


void	Human::Think(){
	std::cout << time(NULL) << " " << this->identify() << "is Thinking" << std::endl;
	this->brain.Ponder();
	std::cout << "You have a sudden craving for spaghettis. If only there were"\
		<< " some forks around here." << std::endl;
}
void	Human::Eat(){
	std::cout << time(NULL) << " " << this->identify() << "is Eating" << std::endl;
	this->time_to_die += 410;
}
void	Human::Sleep(){
	std::cout << time(NULL) << " " << this->identify() << "sleeping" << std::endl;
}
