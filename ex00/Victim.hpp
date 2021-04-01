/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:03:14 by abaur             #+#    #+#             */
/*   Updated: 2021/04/01 16:09:35 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
#define VICTIM_HPP

#include <iostream>

class Victim
{
public:
	Victim(void);
	Victim(const std::string& name);
	Victim(const Victim&);
	virtual ~Victim();
	Victim& operator =(const Victim&);

	std::string getName() const;

	virtual void	getPolymorphed() const;

	virtual std::ostream&	ToStream(std::ostream& dst) const;

protected:
	std::string	name;
};

std::ostream&	operator <<(std::ostream& dst, const Victim& src);

#endif
