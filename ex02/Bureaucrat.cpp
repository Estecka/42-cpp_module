/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:29:04 by abaur             #+#    #+#             */
/*   Updated: 2021/04/08 19:06:14 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <sstream>

Bureaucrat::Bureaucrat(void) {
	this->name = "Nondescript Bureaucrat";
	this->grade = BUREAUGRADEMAX;
}
Bureaucrat::Bureaucrat(const Bureaucrat& other){
	*this = other;
}
Bureaucrat::Bureaucrat(std::string name, int grade) {
	this->name = name;
	this->setGrade(grade);
}
Bureaucrat::~Bureaucrat(){
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other) {
	this->name = other.name;
	this->grade = other.grade;
	return *this;
}

std::string	Bureaucrat::getName() const { return this->name; }
int	Bureaucrat::getGrade() const { return this->grade; }

void	Bureaucrat::setName(std::string name) {
	this->name = name;
}

void	Bureaucrat::setGrade(int grade) {
	if (grade < BUREAUGRADEMIN)
		throw GradeTooHighException(grade);
	if (grade > BUREAUGRADEMAX)
		throw GradeTooLowException(grade);

	this->grade = grade;
}

int	Bureaucrat::upgrade(){
	this->setGrade(this->grade - 1);
	return this->grade;
}

int	Bureaucrat::downgrade(){
	this->setGrade(this->grade + 1);
	return this->grade;
}

bool	Bureaucrat::signForm(Form& form){
	if (form.IsSigned()) 
	{
		std::cout << this->name << " cannot sign the form " << form.GetName() \
			<< " because it is already signed." << std::endl;
		return false;
	}
	else
	{
		try {
			form.beSigned(*this);
		} catch (const Form::GradeTooLowException& e) {
			std::cout << *this << " cannot sign form " << form.GetName() \
				<< " because it requires a grade " << form.GetSigningGrade() \
				<< " or above."\
				<< std::endl;
			return false;
		}
		std::cout << this->name << " signed form " << form.GetName() << std::endl;
		return true;
	}
}

bool	Bureaucrat::executeForm(const Form& form){
	try {
		form.execute(*this);
	}
	catch (const std::logic_error& e) {
		std::cout << this->name << " could not execute " << form.GetName() \
			<< " because it wasn't signed." << std::endl;
		return false;
	}
	catch (const Form::GradeTooLowException& e) {
		std::cout << this->name << " could not execute " << form.GetName() \
			<< " because it requires a grade of " << form.GetExecutingGrade() \
			<< " or above." << std::endl;
		return false;
	}
	std::cout << this->name << " excecuted form " << form.GetName() << std::endl;
	return true;
}

std::ostream&	operator<<(std::ostream& dst, const Bureaucrat& src) {
	return dst << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
}

// =============================================================
Bureaucrat::GradeTooHighException::GradeTooHighException(int grade) throw()
: GradeException("Grade is too high : ", grade){
}
Bureaucrat::GradeTooLowException::GradeTooLowException(int grade) throw()
: GradeException("Grade is too low : ", grade){
}
