/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 14:30:58 by abaur             #+#    #+#             */
/*   Updated: 2021/04/13 18:09:50 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversions.hpp"
#include "conversion_templates.hpp"

#include <iostream>

extern int	main(int argc, char** argv){
	for (int i=1; i<argc; i++) {
		if (i > 1)
			std::cout << "========" << std::endl;

		std::cout << "Input : " << argv[i] << std::endl;

		if(!ConvertChar  (argv[i])
		&& !ConvertInt   (argv[i])
		&& !ConvertDouble(argv[i])
		&& !ConvertFloat (argv[i])
		) {
			std::cout << "Unknown value type" << std::endl;
		}
	}
}