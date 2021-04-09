/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreator.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 19:30:30 by abaur             #+#    #+#             */
/*   Updated: 2021/04/09 15:25:17 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreator.hpp"

#include <exception>
#include <fstream>
#include <sstream>

std::string	ShrubberyCreator::CreateBush(std::string author, std::string target) {
	std::ofstream	ostream;

	ostream.open(
		(target + "_shrubbery").data(), 
		std::ofstream::out | std::ofstream::app
	);
	if (ostream.fail()) {
		std::string	what = "Something happened and " + target + "_shrubbery "\
			"could not be opened.";
		throw std::runtime_error(what);
	}
	ostream << "This tree was planted by " << author << std::endl;


	std::stringstream	tree;
	tree << "Î <(I am a tree!)" << std::endl;
	ostream << tree.str();
	return tree.str();
}