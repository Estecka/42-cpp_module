/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:28:27 by abaur             #+#    #+#             */
/*   Updated: 2021/04/08 18:10:20 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

void	Form::validateGrades() const {
	if (signingGrade > BUREAUGRADEMAX)
		throw GradeTooLowException(signingGrade);
	if (signingGrade < BUREAUGRADEMIN)
		throw GradeTooHighException(signingGrade);
	if (executingGrade > BUREAUGRADEMAX)
		throw GradeTooLowException(executingGrade);
	if (executingGrade < BUREAUGRADEMIN)
		throw GradeTooHighException(executingGrade);
}

Form::Form(void) 
: name("Nondescript Form"), 
signingGrade(BUREAUGRADEMAX), 
executingGrade(BUREAUGRADEMAX)
{
	this->isSigned = false;
	this->validateGrades();
}

Form::Form(const Form& other)
: name(other.name),
signingGrade(other.signingGrade),
executingGrade(other.executingGrade),
target(other.target)
{
	this->isSigned = false;
	this->validateGrades();
}

Form::Form(std::string _name, int _sign, int _exec)
: name(_name),
signingGrade(_sign),
executingGrade(_exec)
{
	this->isSigned = false;
	this->validateGrades();
}

Form&	Form::operator=(const Form& other){
	(void)other;
	throw std::logic_error("A form is constant and cannot be overwritten.");
}

std::string	Form::GetName()   const { return this->name;   }
std::string	Form::GetTarget() const { return this->target; }
int	Form::GetSigningGrade()   const { return this->signingGrade;   }
int	Form::GetExecutingGrade() const { return this->executingGrade; }
bool	Form::IsSigned() const { return this->isSigned; }

bool	Form::beSigned(const Bureaucrat& signer) {
	if (signer.getGrade() > this->signingGrade)
		throw GradeTooLowException(signer.getGrade());
	else if (this->isSigned)
		return false;
	else {
		this->isSigned = true;
		return true;
	}
}

bool	Form::execute(const Bureaucrat& executor) const {
	if (!this->isSigned)
		return false;
	else if (executor.getGrade() > this->executingGrade)
		throw GradeTooLowException(executor.getGrade());
	else
		return true;
}

std::ostream&	operator<<(std::ostream& dst, const Form& src) {
	return dst << "Form " << src.GetName() << ", "\
		<< (src.IsSigned() ? "signed" : "unsigned") << ", "\
		<< "Signing grade " << src.GetSigningGrade() << ", "\
		<< "Executing grade " << src.GetExecutingGrade() << ", "\
		;
}

Form::GradeTooHighException::GradeTooHighException(int grade)
: GradeException("Grade is too high : ", grade)
{}
Form::GradeTooLowException::GradeTooLowException(int grade)
: GradeException("Grade is too low : ", grade)
{}
