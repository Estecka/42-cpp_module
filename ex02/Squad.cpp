/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 17:31:28 by abaur             #+#    #+#             */
/*   Updated: 2021/04/03 18:39:33 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

#include <stdlib.h>

#define DEFAULT_CAP	4

Squad::Squad(void){
	this->content = new ISpaceMarine*[DEFAULT_CAP];
	this->capacity = DEFAULT_CAP;
	this->length = 0;
}
Squad::Squad(const Squad& other)
{
	this->content = new ISpaceMarine*[other.capacity];
	this->capacity = other.capacity;
	this->length = other.length;

	for (int i=0; i<length; i++)
		this->content[i] = other.content[i]->clone();
}
Squad::~Squad(){
}

Squad&	Squad::operator=(const Squad& other){
	for (int i=0; i<this->length; i++)
		delete this->content[i];
	delete[] this->content;

	this->content = new ISpaceMarine*[other.capacity];
	this->capacity = other.capacity;
	this->length = other.length;

	for (int i=0; i<length; i++)
		this->content[i] = other.content[i]->clone();
}

int	Squad::getCount() const {
	return this->length;
}
ISpaceMarine*	Squad::getUnit(int i) const {
	if (i < 0 || this->length <= i)
		return NULL;
	else
		return this->content[i];
}

int	Squad::push(ISpaceMarine* newUnit) {
	this->expand(1);
	this->content[this->length] = newUnit;
	return ++this->length;
}

void	Squad::expand(int newCount){
	while (this->capacity < (this->length + newCount))
		this->capacity *= 2;

	ISpaceMarine** newContent = new ISpaceMarine*[this->capacity];
	for (int i=0; i<this->length; i++)
		newContent[i] = this->content[i];
	
	delete this->content;
	this->content = newContent;
}
