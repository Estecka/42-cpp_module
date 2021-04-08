/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 17:52:06 by abaur             #+#    #+#             */
/*   Updated: 2021/04/08 18:13:40 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
public:
	ShrubberyCreationForm(const ShrubberyCreationForm&);
	ShrubberyCreationForm(std::string target);
	~ShrubberyCreationForm();

	bool	execute(const Bureaucrat& executor) const;

private:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm&);

	const std::string	target;
};

#endif
