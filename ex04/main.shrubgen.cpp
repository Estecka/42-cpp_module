/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.shrubgen.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 18:10:41 by abaur             #+#    #+#             */
/*   Updated: 2021/04/09 18:14:14 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreator.hpp"

#include <stdlib.h>

extern int main(int argc, char** argv) {
	int	bcount;

	if (argc > 1)
		bcount = atoi(argv[1]);
	else
		bcount = 5;
	if (argc > 2)
		srand(atoi(argv[2]));

	ShrubberyCreator::CreateBush(std::cout, bcount);
}