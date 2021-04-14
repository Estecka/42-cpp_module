/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:42:32 by abaur             #+#    #+#             */
/*   Updated: 2021/04/14 17:17:54 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>

static void*	serialize(){
	Data*	data = new Data();

	std::cout << "Serialized data: " << std::endl;
	data->Status();
	return reinterpret_cast<void*>(data);
}

static Data*	deserialize(void* raw){
	Data*	data = reinterpret_cast<Data*>(raw);

	std::cout << "Deserialized data: " << std::endl;
	data->Status();
	return data;
}


extern int	main(){
	srand(time(NULL));

	void*	raw;
	Data*	data;

	raw = serialize();
	data = deserialize(raw);

	delete data;
}