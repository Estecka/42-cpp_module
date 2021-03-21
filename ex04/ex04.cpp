/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:26:32 by abaur             #+#    #+#             */
/*   Updated: 2021/03/21 16:44:47 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

extern int	main(){
	std::string  brain     = "HI THIS IS BRAIN";
	std::string* pointer   = &brain;
	std::string& reference = brain;

	std::cout \
		<< *pointer  << std::endl \
		<< reference << std::endl \
		;
}