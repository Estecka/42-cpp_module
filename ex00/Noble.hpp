/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Noble.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:40:45 by abaur             #+#    #+#             */
/*   Updated: 2021/04/01 15:46:12 by abaur            ###   ########.fr       */
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

	virtual void	getPolymorphed() const;

protected:
	std::string	title;
};

#endif
