/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:14:41 by abaur             #+#    #+#             */
/*   Updated: 2021/04/08 18:15:19 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
public:
	RobotomyRequestForm(const RobotomyRequestForm&);
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm();

	bool	execute(const Bureaucrat& executor) const;

private:
	RobotomyRequestForm(void);
	RobotomyRequestForm&	operator=(const RobotomyRequestForm&);

	const std::string	target;
};

#endif
