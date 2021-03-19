/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memoryLeak.rendu.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 18:27:48 by abaur             #+#    #+#             */
/*   Updated: 2021/03/19 18:27:58 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	memoryLeak()
{
	std::string*	panther = new std::string("String panther");

	std::cout << *panther << std::endl;
	delete panther;
}