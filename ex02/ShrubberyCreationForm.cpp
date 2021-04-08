/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:38:21 by abaur             #+#    #+#             */
/*   Updated: 2021/04/08 18:40:02 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <exception>

ShrubberyCreationForm::ShrubberyCreationForm(void) {
	throw std::invalid_argument("Void Shrubbery not supported.");
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: Form(other)
{}
ShrubberyCreationForm::ShrubberyCreationForm(std::string _target)
: Form("Shrubbery Creation", 145, 137),
target(_target)
{}
ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
	(void)other;
	throw std::logic_error("Forms are constant and cannot be overwritten.");
}

bool	ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	this->Form::execute(executor);
	std::cout << this->target << " shrubbery tree on its way to creation. Please stand by..." << std::endl;
	return true;
}
