/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 20:56:12 by abaur             #+#    #+#             */
/*   Updated: 2021/04/05 00:49:08 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void){
	this->name = "Nameless Protagonist";
	this->invCount = 0;
	for (int i=0; i<INVMAX; i++)
		this->inventory[i] = NULL;
}
Character::Character(const std::string& name){
	this->name = name;
	this->invCount = 0;
	for (int i=0; i<INVMAX; i++)
		this->inventory[i] = NULL;
}
Character::Character(const Character& other){
	*this = other;
}
Character::~Character(){
	for(int i=0; i<invCount; i++)
		delete this->inventory[i];
}

Character&	Character::operator=(const Character& other){
	this->name = other.name;
	this->invCount = other.invCount;
	for (int i=0; i<invCount; i++)
		this->inventory[i] = other.inventory[i]->clone();
	for (int i=invCount; i<INVMAX; i++)
		this->inventory[i] = NULL;
	return *this;
}

const std::string&	Character::getName() const { return this->name; }

void	Character::status() const {
	std::cout << this->name << " | " << this->invCount << " materias" << std::endl;
	for (int i=0; i<INVMAX; i++)
	{
		AMateria* item = this->inventory[i];
		std::cout << "["<<i<<"] " << item;
		if (item)
			std::cout << " " << item->getType() << " ("<<item->getXP()<<")";
		std::cout << std::endl;
	}
}

bool	Character::equip(AMateria* item){
	if (!item || this->invCount >= INVMAX)
		return false;
	else {
		for (int i=0; i<invCount; i++)
			if (this->inventory[i] == item)
				return false;

		this->inventory[invCount] = item;
		invCount++;
		return true;
	}
}
AMateria*	Character::unequip(int index){
	if (index < 0 || invCount <= index)
		return NULL;
	else {
		AMateria*	item;
		
		item = this->inventory[index];
		for (int i=index; i<(invCount-1); i++)
			inventory[i] = inventory[i+1];
		invCount--;
		inventory[invCount] = NULL;
		return item;
	}
}

bool	Character::use(int index, ICharacter& target){
	if (index < 0 || invCount <= index)
		return false;
	else {
		this->inventory[index]->use(target);
		return false;
	}
}
