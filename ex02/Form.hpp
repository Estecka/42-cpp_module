/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:01:13 by abaur             #+#    #+#             */
/*   Updated: 2021/04/09 19:20:59 by abaur            ###   ########.fr       */
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
	Form(std::string name, int signingGrade, int executingGrade, std::string target);
	virtual ~Form() = 0;

	std::string	GetName() const;
	std::string	GetTarget() const;
	int	GetSigningGrade() const;
	int	GetExecutingGrade() const;
	bool	IsSigned() const;

	bool	beSigned(const Bureaucrat& signer);

	virtual bool	execute(const Bureaucrat& executor) const;

private:
	const std::string	target;
	Form&	operator=(const Form&);
	const std::string	name;
	const int	signingGrade;
	const int	executingGrade;

	bool	isSigned;

	void	validateGrades() const;

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
