/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeException.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:50:24 by abaur             #+#    #+#             */
/*   Updated: 2021/04/07 16:55:11 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADEEXCEPTION_HPP
#define GRADEEXCEPTION_HPP

#include <exception>
#include <iostream>

class GradeException : public std::exception 
{
public:
	GradeException(int grade) throw();
	~GradeException() throw();
	const char* what() const throw();

protected:
	GradeException(std::string what, int grade) throw();

private:
	int _grade;
	std::string	_what;
};

#endif
