/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:19:12 by abaur             #+#    #+#             */
/*   Updated: 2021/04/08 18:32:42 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

#include <exception>

PresidentialPardonForm::PresidentialPardonForm(void) {
	throw std::invalid_argument("Void Presidential Pardon not supported.");
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
: Form(other)
{}
PresidentialPardonForm::PresidentialPardonForm(std::string _target)
: Form("Presidential Pardon", 25, 5),
target(_target)
{}
PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
	(void)other;
	throw std::logic_error("Forms are constant and cannot be overwritten.");
}

bool	PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	this->Form::execute(executor);
	std::cout << this->target << " has been pardoned by Zafod Beeblebrox." << std::endl;
	return true;
}
