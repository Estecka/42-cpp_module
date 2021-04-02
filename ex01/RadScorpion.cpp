/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 19:54:04 by abaur             #+#    #+#             */
/*   Updated: 2021/04/02 15:07:44 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"

RadScorpion::RadScorpion(void)
: Enemy(80, "RadScorpion") {
	this->deathCry = "* SPROTCH *";
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(const RadScorpion& other)
: Enemy(other) {
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion(){
}

RadScorpion& RadScorpion::operator =(const RadScorpion& other){
	this->Enemy::operator=(other);
	return *this;
}
