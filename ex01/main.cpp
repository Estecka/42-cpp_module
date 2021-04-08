/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:11:20 by abaur             #+#    #+#             */
/*   Updated: 2021/04/08 17:22:54 by abaur            ###   ########.fr       */
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

extern int	main()
{
	{
		Form*	f;

		std::cout << std::endl << "Creating invalid forms..." << std::endl;
		try { f = new Form("W", 0, 1);   } catch (const GradeException& e) { std::cout << e.what() << std::endl; }
		try { f = new Form("X", 151, 1); } catch (const GradeException& e) { std::cout << e.what() << std::endl; }
		try { f = new Form("Y", 2, 0);   } catch (const GradeException& e) { std::cout << e.what() << std::endl; }
		try { f = new Form("Z", 2, 156); } catch (const GradeException& e) { std::cout << e.what() << std::endl; }
	}
	{
		std::cout << std::endl << "Signing a bunch of forms..." << std::endl;
		bureaucrats[0].signForm(forms[0]);
		bureaucrats[6].signForm(forms[6]);
		bureaucrats[6].signForm(forms[0]);
		bureaucrats[6].signForm(forms[1]);
		bureaucrats[1].signForm(forms[5]);
		bureaucrats[2].signForm(forms[2]);
		bureaucrats[2].signForm(forms[3]);
		bureaucrats[1].signForm(forms[3]);
		bureaucrats[4].signForm(forms[3]);
		bureaucrats[5].signForm(forms[5]);
	}
}
