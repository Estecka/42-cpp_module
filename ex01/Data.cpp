/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:11:12 by abaur             #+#    #+#             */
/*   Updated: 2021/04/14 17:20:38 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

#include <stdlib.h>

static std::string	RandomString(){
	char	str[9];

	for (int i=0; i<8; i++)
		str[i] = 'a' + (rand() % ('z'-'a'));
	str[8] = '\0';

	return std::string(str);
}

Data::Data(void){
	this->s1 = RandomString();
	this->s2 = RandomString();
	this->n  = rand();
}

void Data::Status() const {
	std::cout \
		<< "\ts1 = " << this->s1 << std::endl \
		<< "\tn  = " << this->n  << std::endl \
		<< "\ts2 = " << this->s2 << std::endl \
		;
}
