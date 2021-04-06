/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:16:20 by abaur             #+#    #+#             */
/*   Updated: 2021/04/06 15:22:17 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
public:
	Bureaucrat(void);
	Bureaucrat(const Bureaucrat&);
	Bureacrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat&	operator=(const Bureaucrat&);

	std::string	getName() const;
	int	getGrade() const;

	void	setName(std::string name);
	void	setGrade(int grade);

	int	upgrade();
	int	downgrade();

private:
	std::string	name;
	int	grade;
};


#endif
