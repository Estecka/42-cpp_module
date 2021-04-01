/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Noble.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:40:45 by abaur             #+#    #+#             */
/*   Updated: 2021/04/01 16:14:19 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NOBLE_HPP
#define NOBLE_HPP

#include "Victim.hpp"

class Noble : public Victim
{
public:
	Noble(void);
	Noble(const std::string& name, const std::string& title);
	Noble(const Noble&);
	~Noble();
	Noble& operator =(const Noble&);

	std::string	getTitle() const;
	virtual std::ostream&	ToStream(std::ostream& dst) const;

	virtual void	getPolymorphed() const;

protected:
	std::string	title;
};

#endif
