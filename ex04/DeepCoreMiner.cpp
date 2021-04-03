/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DeepCoreMiner.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:15:29 by abaur             #+#    #+#             */
/*   Updated: 2021/04/04 00:08:54 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DeepCoreMiner.hpp"

DeepCoreMiner::DeepCoreMiner(void){
}
DeepCoreMiner::DeepCoreMiner(const DeepCoreMiner& other){
	*this = other;
}
DeepCoreMiner::~DeepCoreMiner(){
}

DeepCoreMiner&	DeepCoreMiner::operator=(const DeepCoreMiner& other){
	return *this;
}

std::string	DeepCoreMiner::getName() { return "DeepCoreMiner"; }

std::string	DeepCoreMiner::mine(IAsteroid* target){
	std::string	result;

	if (target == NULL)
		result = "nothing";
	else
		result = target->beMined(this);

	std::cout << "* strip mining... got " << result << "! *" << std::endl;
	return result;
}
