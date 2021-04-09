/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreator.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 19:30:30 by abaur             #+#    #+#             */
/*   Updated: 2021/04/09 18:16:08 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreator.hpp"

#include <cwchar>
#include <exception>
#include <fstream>
#include <sstream>
#include <stdlib.h>

enum	EBranch {
	branchNone  = 0,
	branchLeft  = 1 << 0,
	branchDown  = 1 << 1,
	branchRight = 1 << 2,
	branchUp    = 1 << 3,
	branchAll   = branchUp | branchLeft | branchRight | branchDown,
};

static const char*	GetBranch(short directions){
	switch ((short)directions)
	{
		default:
			return "?";

		case branchAll:
			return "┼";

		case branchAll & ~branchUp:
			return "┬";
		case branchAll & ~branchLeft:
			return "├";
		case branchAll & ~branchRight:
			return "┤";
		case branchAll & ~branchDown:
			return "┴";

		case branchLeft | branchDown:
			return "┐";
		case branchLeft | branchUp:
			return "┘";
		case branchRight | branchDown:
			return "┌";
		case branchRight | branchUp:
			return "└";

		case branchUp | branchDown:
			return "│";
		case branchRight | branchLeft:
			return "─";
		
		case branchUp:    return "╹";
		case branchDown:  return "╻";
		case branchLeft: return "╸";
		case branchRight:  return "╺";
	}
}

static std::stringstream&	printNest(std::stringstream& dst, int nestLvl){
	for (int i=0; i<nestLvl; i++)
		dst << GetBranch(branchUp | branchDown);
	return dst;
}

static int	drawBranch(std::stringstream& dst, int leafMax, int nestLvl){
	(void)nestLvl;
	int	branchCount = leafMax ? rand() % leafMax : 0;
	if (!branchCount)
		dst << GetBranch(branchLeft) << std::endl;

	for (int i=0; i<branchCount; i++){
		short branchType = branchNone;
		if (i == 0)
			branchType |= branchLeft;
		else
			branchType |= branchUp;

		if (rand()%2) {
			branchType |= branchDown;
			if (i)
				printNest(dst, nestLvl);
			dst << GetBranch(branchType);
			dst << std::endl;
			branchType &= ~branchLeft;
			branchType &= ~branchDown;
			branchType |= branchUp;
		}

		if (i+1 != branchCount)
			branchType |= branchDown;
		branchType |= branchRight;
		if (i)
			printNest(dst, nestLvl);
		dst << GetBranch(branchType);
		drawBranch(dst, leafMax - branchCount, nestLvl + 1);
	}
	return leafMax - branchCount;
}

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
	return CreateBush(ostream, 5);
}
std::string	ShrubberyCreator::CreateBush(std::ostream& dst, int branchCount) {
	std::stringstream	tree;

	drawBranch(tree, branchCount, 0);
	dst << tree.str();
	return tree.str();
}
