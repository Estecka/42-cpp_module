/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DeepCoreMiner.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 23:05:50 by abaur             #+#    #+#             */
/*   Updated: 2021/04/05 17:37:04 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEEPCOREMINER_HPP
#define DEEPCOREMINER_HPP

#include "IMiningLaser.hpp"

#include <iostream>

class IAsteroid;

class DeepCoreMiner : public IMiningLaser
{
public:
	DeepCoreMiner(void);
	DeepCoreMiner(const DeepCoreMiner&);
	~DeepCoreMiner();
	DeepCoreMiner& operator=(const DeepCoreMiner&);

	std::string	getName() const;
	int	getDurability() const;
	int	getFullPrice() const;
	int	getWorth() const;

	std::string	mine(IAsteroid* target);
	IMiningLaser*	clone() const;
};

#include "IAsteroid.hpp"

#endif
