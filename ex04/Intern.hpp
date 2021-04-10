/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 19:46:24 by abaur             #+#    #+#             */
/*   Updated: 2021/04/09 19:56:36 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>

class Intern
{
public:
	Intern();
	Intern(const Intern&);
	~Intern();
	Intern&	operator=(const Intern&);

	Form*	makeForm(std::string type, std::string target);

	static Form*	makePardon(std::string target);
	static Form*	makeRobotomy(std::string target);
	static Form*	makeShrubbery(std::string target);
};

#endif
