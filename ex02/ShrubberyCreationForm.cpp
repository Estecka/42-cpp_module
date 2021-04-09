/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:38:21 by abaur             #+#    #+#             */
/*   Updated: 2021/04/09 19:25:37 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "ShrubberyCreator.hpp"

#include <exception>

ShrubberyCreationForm::ShrubberyCreationForm(void) {
	throw std::invalid_argument("Void Shrubbery not supported.");
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: Form(other)
{}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: Form("Shrubbery Creation", 145, 137, target)
{}
ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
	(void)other;
	throw std::logic_error("Forms are constant and cannot be overwritten.");
}

bool	ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	std::string	tree;

	this->Form::execute(executor);
	std::cout << this->GetTarget() << " shrubbery tree on its way to creation. Please stand by..." << std::endl;
	try {
		tree = ShrubberyCreator::CreateBush(executor.getName(), this->GetTarget());
	}
	catch (const std::runtime_error& e){
		std::cout << e.what() << std::endl;
		return false;
	}
	std::cout << executor.getName() << " planted a tree, "\
		"look at that sick tree !" << std::endl \
		<< tree;

	return true;
}
