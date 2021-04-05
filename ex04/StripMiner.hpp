/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StripMiner.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:12:40 by abaur             #+#    #+#             */
/*   Updated: 2021/04/05 17:37:15 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRIPMINER_HPP
#define STRIPMINER_HPP

#include "IMiningLaser.hpp"
#include <iostream>

class IAsteroid;

class StripMiner : public IMiningLaser
{
public:
	StripMiner(void);
	StripMiner(const StripMiner&);
	~StripMiner();
	StripMiner&	operator=(const StripMiner&);

	std::string	getName() const;
	int	getDurability() const;
	int	getFullPrice() const;
	int	getWorth() const;

	std::string	mine(IAsteroid* target);
	IMiningLaser*	clone() const;
};

#include "IAsteroid.hpp"

#endif
