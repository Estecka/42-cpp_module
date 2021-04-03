/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StripMiner.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:12:40 by abaur             #+#    #+#             */
/*   Updated: 2021/04/04 00:52:26 by abaur            ###   ########.fr       */
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

	std::string	mine(IAsteroid* target);
};

#include "IAsteroid.hpp"

#endif
