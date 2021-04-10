/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 19:28:02 by abaur             #+#    #+#             */
/*   Updated: 2021/04/09 18:14:21 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATOR_HPP
#define SHRUBBERYCREATOR_HPP

#include <iostream>

namespace ShrubberyCreator
{
	std::string	CreateBush(std::string author, std::string target);
	std::string	CreateBush(std::ostream& dst, int bcount);
}

#endif
