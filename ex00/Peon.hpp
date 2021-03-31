/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:09:26 by abaur             #+#    #+#             */
/*   Updated: 2021/03/31 18:23:22 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
#define PEON_HPP

#include "Victim.hpp"
#include <iostream>

class Peon : public Victim
{
public:
	Peon(void);
	Peon(std::string name);
	Peon(const Peon&);
	~Peon();
	Peon& operator =(const Peon&);


	virtual void	getPolymorphed() const;
};

#endif
