/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:11:20 by abaur             #+#    #+#             */
/*   Updated: 2021/04/08 19:24:10 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

static void	tryExecForm(Bureaucrat& bureaucrat, Form& form){
	std::cout << std::endl \
		<< "+ " << bureaucrat << std::endl \
		<< "+ " << form << std::endl \
		<< ">> ";
	bureaucrat.executeForm(form);
	std::cout << std::endl;
}

static void	trySignForm(Bureaucrat& bureaucrat, Form& form){
	std::cout << std::endl \
		<< "+ " << bureaucrat << std::endl \
		<< "+ " << form << std::endl \
		<< ">> ";
	bureaucrat.signForm(form);
	std::cout << std::endl;
}

extern int	main()
{
	Bureaucrat	gardenerInChief("Gardener in Chief", 137);
	Bureaucrat	gardenerTrainee("Gardener Trainee", 145);
	Bureaucrat	robotomiserInChief("Robotomiser in Chief", 45);
	Bureaucrat	robotomiserTrainee("Robotomiser Trainee", 72);
	Bureaucrat	presidentSenior("Zafod Beeblebrox Senior", 1);
	Bureaucrat	presidentJunior("Zafod Beeblebrox Junior", 25);

	PresidentialPardonForm	pardon("The Captain of the EverGiven");
	RobotomyRequestForm	robotomy("The coffee machine");
	ShrubberyCreationForm shrubbery("garden");

	std::cout << std::endl << "== Presidential Pardon ==" << std::endl;
	trySignForm(gardenerInChief, pardon);
	tryExecForm(presidentSenior, pardon);
	trySignForm(presidentJunior, pardon);
	tryExecForm(presidentSenior, pardon);

	std::cout << std::endl << "== Robotomy Request ==" << std::endl;
	trySignForm(robotomiserTrainee, robotomy);
	tryExecForm(robotomiserTrainee, robotomy);
	tryExecForm(gardenerInChief, robotomy);
	tryExecForm(robotomiserInChief, robotomy);
	tryExecForm(presidentJunior, robotomy);
	tryExecForm(presidentSenior, robotomy);

	std::cout << std::endl << "== Shrubbery Creation ==" << std::endl;
	trySignForm(presidentJunior, shrubbery);
	trySignForm(gardenerTrainee, shrubbery);
	tryExecForm(gardenerTrainee, shrubbery);
	tryExecForm(gardenerInChief, shrubbery);
	tryExecForm(robotomiserTrainee, shrubbery);
	tryExecForm(robotomiserInChief, shrubbery);
	tryExecForm(presidentSenior, shrubbery);
	tryExecForm(presidentJunior, shrubbery);
}
