/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:37:31 by abaur             #+#    #+#             */
/*   Updated: 2021/04/14 18:49:32 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <time.h>

Base*	generate(){
	switch (rand() % 3) {
		default: throw std::out_of_range("Invalid random value");
		case 0:  return new A();
		case 1:  return new B();
		case 2:  return new C();
	}
}

void	identify_from_pointer(Base* ptr){
	if (dynamic_cast<A*>(ptr))
		std::cout << "Ptr is a A" << std::endl;
	else if (dynamic_cast<B*>(ptr))
		std::cout << "Ptr is a B" << std::endl;
	else if (dynamic_cast<C*>(ptr))
		std::cout << "Ptr is a C" << std::endl;
	else
		std::cout << "I have no idea what this pointer is." << std::endl;
}

template <typename T> bool	IsRefType(Base& ref, const char* name){
	try {
		(void)dynamic_cast<T&>(ref);
		std::cout << "Ref is a " << name << std::endl;
		return true;
	}
	catch (const std::exception&){
		return false;
	}
}

void	identify_from_reference(Base& ref){
	if (!IsRefType<A>(ref, "A") 
	 && !IsRefType<B>(ref, "B") 
	 && !IsRefType<C>(ref, "C") )
		std::cout << "I have no idea what this reference is." << std::endl;
}

extern int	main(int argc, char** argv){
	if (argc > 1)
		srand(argv[1][0]);
	else
		srand(time(NULL));

	Base* ptr =	generate();
	Base& ref = *ptr;

	identify_from_pointer(ptr);
	identify_from_reference(ref);
}
