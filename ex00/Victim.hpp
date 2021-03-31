/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:03:14 by abaur             #+#    #+#             */
/*   Updated: 2021/03/31 18:54:35 by abaur            ###   ########.fr       */
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
	~Victim();
	Victim& operator =(const Victim&);

	std::string getName() const;

	virtual void	getPolymorphed() const;

private:
	std::string	name;
};

std::ostream&	operator <<(const std::ostream& dst, const Victim& src);

#endif
