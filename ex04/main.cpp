/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:11:20 by abaur             #+#    #+#             */
/*   Updated: 2021/04/10 15:05:44 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

extern int	main()
{
	Bureaucrat	zafodBleeblebrox("Zafod Beeblebrox", 1);
	Intern	someIntern;

	Form*	f;

	f = someIntern.makeForm("presidential pardon", "The intern who spilled cofee");
	zafodBleeblebrox.signForm(*f);
	zafodBleeblebrox.executeForm(*f);
	delete f;
	std::cout << std::endl;

	f = someIntern.makeForm("robotomy request", "The coffee cup");
	zafodBleeblebrox.signForm(*f);
	zafodBleeblebrox.executeForm(*f);
	delete f;
	std::cout << std::endl;

	f = someIntern.makeForm("shrubbery creation", "garden");
	zafodBleeblebrox.signForm(*f);
	zafodBleeblebrox.executeForm(*f);
	zafodBleeblebrox.executeForm(*f);
	zafodBleeblebrox.executeForm(*f);
	delete f;
	std::cout << std::endl;

	f = someIntern.makeForm("form", "pile of paper");
	std::cout << f << std::endl;
	std::cout << std::endl;

	f = someIntern.makeForm("planetary anihilation", "Mars");
	std::cout << f << std::endl;
	std::cout << std::endl;
}
