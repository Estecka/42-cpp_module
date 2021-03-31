/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:44:44 by abaur             #+#    #+#             */
/*   Updated: 2021/03/31 18:27:39 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
#define SORCERER_HPP

#include "Victim.hpp"
#include <iostream>

class Sorcerer
{
public:
	Sorcerer(const std::string& name, const std::string& title);
	Sorcerer(const Sorcerer&);
	~Sorcerer();
	Sorcerer&	operator =(const Sorcerer&);

	std::string	getName() const;
	std::string	getTitle() const;

	void	polymorph(const Victim&) const;

private:
	Sorcerer(void);

	std::string	name;
	std::string	title;
};

std::ostream&	operator <<(std::ostream& dst, const Sorcerer& src);

#endif
