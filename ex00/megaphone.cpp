/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:47:38 by abaur             #+#    #+#             */
/*   Updated: 2021/03/15 21:15:48 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static void	toupper(char* s){
	while (*s)
	{
		if ( 'a' <= *s && *s <= 'z')
			*s += 'A' - 'a';
		s++;
	}
}

extern int	main(int argc, char** argv) {
	if (argc <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		for (int i=1; i<argc; i++) {
			toupper(argv[i]);
			std::cout << argv[i];
		}
		std::cout << std::endl;
	}
}
