/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:16:03 by abaur             #+#    #+#             */
/*   Updated: 2021/04/08 18:16:36 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
public:
	PresidentialPardonForm(const PresidentialPardonForm&);
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm();

	bool	execute(const Bureaucrat& executor) const;

private:
	PresidentialPardonForm(void);
	PresidentialPardonForm&	operator=(const PresidentialPardonForm&);

	const std::string	target;
};

#endif
