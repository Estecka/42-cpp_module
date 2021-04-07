/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:16:20 by abaur             #+#    #+#             */
/*   Updated: 2021/04/07 17:27:13 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "GradeException.hpp"

#include "Form.hpp"
#include <iostream>
#include <exception>

#define BUREAUGRADEMIN	1
#define BUREAUGRADEMAX	150

class Form;

class Bureaucrat
{
public:
	Bureaucrat(void);
	Bureaucrat(const Bureaucrat&);
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat&	operator=(const Bureaucrat&);

	std::string	getName() const;
	int	getGrade() const;

	void	setName(std::string name);
	void	setGrade(int grade);

	bool	signForm(const Form&);

	int	upgrade();
	int	downgrade();

private:
	std::string	name;
	int	grade;

//==================================================
public:
	class GradeTooHighException : public GradeException
	{
	public:
		GradeTooHighException(int grade) throw();
	};

	class GradeTooLowException : public GradeException
	{
	public:
		GradeTooLowException(int grade) throw();
	};
};

std::ostream&	operator<<(std::ostream&, const Bureaucrat&);

#endif
