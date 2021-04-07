/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:11:20 by abaur             #+#    #+#             */
/*   Updated: 2021/04/07 17:26:30 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static const std::string	names[] = {
	"Robert",
	"Norbert",
	"Francis",
	"Fabrice",
	"Josephine",
	"Camille",
	"Marguerite"
};

static const int	grades[] = {
	0,
	1,
	2,
	75,
	149,
	150,
	151,
};

extern int	main() {
	for (int i=0; i<7; i++)
	{
		Bureaucrat*	minion = NULL;

		std::cout << std::endl << "== " << names[i] << ", grade " << grades[i] << " ==" << std::endl;
		std::cout << "Creating bureaucrat..." << std::endl;
		try {
			minion = new Bureaucrat(names[i], grades[i]);
		}
		catch(const GradeException& e) {
			std::cout << "!! An exception was thrown !!" << std::endl \
				<< e.what() << std::endl;
				;
		}

		std::cout << names[i] <<"'s pointer is " << minion << std::endl;
		if (!minion){
			std::cout << names[i] << " was not created." << std::endl;
			continue;
		}
		std::cout << *minion << std::endl;


		std::cout << "Upgrading once..." << std::endl;
		try {
			minion->upgrade();
		}
		catch(const GradeException& e) {
			std::cout << "!! An exception was thrown !!" << std::endl \
				<< e.what() << std::endl;
		}
		std::cout << minion->getName() << "'s grade is "\
			 << minion->getGrade() << "." << std::endl;


		std::cout << "Downgrading twice..." << std::endl;
		try {
			minion->downgrade();
			minion->downgrade();
		}
		catch(const GradeException& e) {
			std::cout << "!! An exception was thrown !!" << std::endl \
				<< e.what() << std::endl;
		}
		std::cout << minion->getName() << "'s grade is "\
			 << minion->getGrade() << "." << std::endl;


		std::cout << "Disposing " << minion->getName() << "." << std::endl;
		delete minion;
		continue;
	}
}
