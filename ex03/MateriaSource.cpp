/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 22:42:12 by abaur             #+#    #+#             */
/*   Updated: 2021/04/04 22:56:13 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void){
	this->invCount = 0;
	for (int i=0; i<4; i++)
		this->inventory[i] = NULL;
}
MateriaSource::MateriaSource(const MateriaSource& other){
	*this = other;
}
MateriaSource::~MateriaSource(){
	for (int i=0; i<invCount; i++)
		delete this->inventory[i];
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other) {
	this->invCount = other.invCount;
	for (int i=0; i<invCount; i++)
		this->inventory[i] = other.inventory[i]->clone();
	for (int i=invCount; i<4; i++)
		this->inventory[i] = NULL;
	return *this;
}

void	MateriaSource::learnMateria(const AMateria* materia){
	if (materia && this->invCount < 4){
		this->inventory[invCount] = materia->clone();
		this->invCount++;
	}
}

AMateria*	MateriaSource::createMateria(const std::string& type){
	for (int i=0; i<invCount; i++)
		if (type == this->inventory[i]->getType())
			return this->inventory[i]->clone();
	return NULL;
}
