/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 18:12:55 by abaur             #+#    #+#             */
/*   Updated: 2021/04/02 14:57:20 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

#include <exception>

Enemy::Enemy(void){
	throw std::invalid_argument("(void) constructor not supported.");
}

Enemy::Enemy(const Enemy& other){
	*this = other;
}

Enemy::Enemy(int hp, const std::string& type){
	this->healthPoints = hp;
	this->type = type;
}
Enemy::~Enemy(){
}

Enemy& Enemy::operator=(const Enemy& other){
	this->type = other.type;
	this->healthPoints = other.healthPoints;
	this->deathCry = other.deathCry;
	return *this;
}

std::string	Enemy::getType() const { return this->type; }
int	Enemy::getHP() const { return this->healthPoints; }

void	Enemy::takeDamage(int dmgAmount){
	if (dmgAmount > this->healthPoints)
		dmgAmount = healthPoints;
	if (dmgAmount > 0) {
		this->healthPoints -= dmgAmount;
		if (!healthPoints)
			std::cout << this->deathCry << std::endl;
	}
}
