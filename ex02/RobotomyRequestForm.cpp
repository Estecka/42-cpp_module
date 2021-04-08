/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:32:11 by abaur             #+#    #+#             */
/*   Updated: 2021/04/08 19:25:09 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include <exception>
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm(void) {
	throw std::invalid_argument("Void Robotomy not supported.");
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: Form(other)
{}
RobotomyRequestForm::RobotomyRequestForm(std::string _target)
: Form("Robotomy Request", 72, 45),
target(_target)
{}
RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
	(void)other;
	throw std::logic_error("Forms are constant and cannot be overwritten.");
}

bool	RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	this->Form::execute(executor);
	std::cout << "* TACTACTACTACTACTACTAC *" << std::endl;
	if (rand() % 2) {
		std::cout << target << " has been robotomised succesfully." << std::endl;
		return true;
	}
	else {
		std::cout << target<<"'s robotomisation was a failure." << std::endl;
		return false;
	}
}
