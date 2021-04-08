/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:11:20 by abaur             #+#    #+#             */
/*   Updated: 2021/04/08 17:33:18 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

static Bureaucrat	bureaucrats[] = {
	Bureaucrat("Jeanne", BUREAUGRADEMIN),
	Bureaucrat("Marceline", 50),
	Bureaucrat("Morgan", 93),
	Bureaucrat("Alfred", 142),
	Bureaucrat("Arthur", BUREAUGRADEMAX),
	Bureaucrat(bureaucrats[4]),
	Bureaucrat(),
};

static Form	forms[] = {
	Form("A1", BUREAUGRADEMIN, 1),
	Form("B2", 2, 1),
	Form("C3", 50, 1),
	Form("D4", 100, 1),
	Form("E5", BUREAUGRADEMAX, 1),
	Form(forms[4]),
	Form(),
};

static void	tryCreateForm(std::string name, int sign, int exec){
	Form*	f;

	try  {
		f = new Form(name, sign, exec);
	}
	catch (const GradeException& e)	{ 
		std::cout << name << " " << e.what() << std::endl;
	}

	if (f) {
		std::cout << *f << std::endl;
		delete f;
	}
}

static void	trySignForm(Bureaucrat& bureaucrat, Form& form){
	std::cout << std::endl;
	std::cout << "+ " << bureaucrat << std::endl;
	std::cout << "+ " << form << std::endl;
	std::cout << ">> "; bureaucrat.signForm(form);
	std::cout << std::endl;
}

extern int	main()
{
	{
		std::cout << std::endl << "== Creating some forms ==" << std::endl;
		tryCreateForm("Invalid-W", 0, 1);
		tryCreateForm("Invalid-X", 151, 1);
		tryCreateForm("Invalid-Y", 1, 0);
		tryCreateForm("Invalid-Z", 1, 151);

		tryCreateForm("Valid-W", 2, 149);
		tryCreateForm("Valid-X", 1, 150);
		tryCreateForm("Valid-Y", 150, 1);
		tryCreateForm("Valid-Z", 2, 149);
	}
	{
		std::cout << std::endl << "==== Signing a bunch of forms... ====" << std::endl;
		trySignForm(bureaucrats[0], forms[0]);
		trySignForm(bureaucrats[6], forms[6]);
		trySignForm(bureaucrats[6], forms[0]);
		trySignForm(bureaucrats[6], forms[1]);
		trySignForm(bureaucrats[1], forms[5]);
		trySignForm(bureaucrats[2], forms[2]);
		trySignForm(bureaucrats[2], forms[3]);
		trySignForm(bureaucrats[1], forms[3]);
		trySignForm(bureaucrats[4], forms[3]);
		trySignForm(bureaucrats[5], forms[5]);
	}
}
