/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMiningLaser.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:10:04 by abaur             #+#    #+#             */
/*   Updated: 2021/04/05 18:09:02 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMININGLASER_HPP
#define IMININGLASER_HPP

#include <iostream>

class IAsteroid;

class IMiningLaser
{
public:
	virtual ~IMiningLaser() {}

	virtual std::string	getName() const = 0;
	virtual int	getDurability() const = 0;
	virtual int	getDurabilityMax() const = 0;
	virtual int	getFullPrice() const = 0;

	virtual std::string mine(IAsteroid* target) = 0;
	virtual IMiningLaser*	clone() const = 0;

protected:
	int	durability;
};

#include "IAsteroid.hpp"

#endif
