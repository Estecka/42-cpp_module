/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeException.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:53:00 by abaur             #+#    #+#             */
/*   Updated: 2021/04/07 16:53:51 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GradeException.hpp"

#include <sstream>

GradeException::GradeException(int grade) throw() {
	std::stringstream what;

	what << "Grade is invalid : " << grade;
	this->_grade = grade;
	this->_what = what.str();
}
GradeException::GradeException(std::string whatchar, int grade) throw() {
	std::stringstream whatstream;

	whatstream << whatchar << grade;
	this->_grade = grade;
	this->_what = whatstream.str();
}
GradeException::~GradeException() throw(){
}

const char*	GradeException::what() const throw(){
	return this->_what.data();
}
