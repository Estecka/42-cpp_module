/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 19:50:40 by abaur             #+#    #+#             */
/*   Updated: 2021/04/09 21:14:27 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void){}
Intern::Intern(const Intern&){}
Intern::~Intern(){}
Intern& Intern::operator=(const Intern&){ return *this; }

Form*	Intern::makePardon   (std::string target) { return new PresidentialPardonForm(target); }
Form*	Intern::makeRobotomy (std::string target) { return new RobotomyRequestForm   (target); }
Form*	Intern::makeShrubbery(std::string target) { return new ShrubberyCreationForm (target); }

#define TYPECOUNTS	3

static Form*(*const funcs[TYPECOUNTS])(std::string) = {
	&Intern::makePardon,
	&Intern::makeRobotomy,
	&Intern::makeShrubbery,
};
static const char* names[TYPECOUNTS] = {
	"presidential pardon",
	"robotomy request",
	"shrubbery creation",
};

Form*	Intern::makeForm(std::string type, std::string target){
	for (int i=0; i<TYPECOUNTS; i++)
		if (names[i] == type)
			return funcs[i](target);
	return NULL;
}
