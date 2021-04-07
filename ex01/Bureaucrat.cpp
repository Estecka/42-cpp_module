/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:29:04 by abaur             #+#    #+#             */
/*   Updated: 2021/04/07 17:26:56 by abaur            ###   ########.fr       */
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
