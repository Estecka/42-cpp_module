/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:01:13 by abaur             #+#    #+#             */
/*   Updated: 2021/04/07 17:19:50 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

#include <iostream>

class Bureaucrat;

class Form
{
public:
	Form(void);
	Form(const Form&);
	Form(std::string name, int signingGrade, int executingGrade);
	~Form();
	const Form&	operator=(const Form&);

	std::string	GetName() const;
	int	GetSigningGrade() const;
	int	GetExecutingGrade() const;

	std::string	ToString() const;

	void	beSigned(const Bureaucrat& signer);

private:
	const std::string	name;
	const int	signingGrade;
	const int	executingGrade;

//=======================================================
public:
	class GradeTooHighException : public GradeException {
	public:
		GradeTooHighException(int grade);
	};
	class GradeTooLowException : public GradeException {
	public:
		GradeTooLowException(int grade);
	};
};

std::ostream&	operator<<(std::ostream& dst, const Form& src);

#endif
